#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <SDL2/SDL.h>
#include "imgui_impl_opengl3_loader.h"
   // Initialize with gl3wInit()

#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h> // for gethostname
#include <cstdlib>
#include <dirent.h> // for opendir, readdir, closedir
#include <vector>
#include <algorithm> // for std::sort
#include <cstring> // for strspn, strlen
#include <sstream> // for std::istringstream
#include <sys/statvfs.h> // for statvfs
#include <sys/types.h> // for DIR, struct dirent
#include <sys/stat.h> // for stat

using namespace std;

string GetOSName(){
    ifstream osfile("/etc/os-release");
    string line;
    bool found = false;
    while(getline(osfile,line))
    {
        if (line.find("PRETTY_NAME") !=std::string::npos)
        {
            found = true;
            return line.substr(line.find("=") + 1);
        }
    }
    if (!found)
    {
        return "OS type not found.";
    }
    osfile.close();
    return "OS type not found.";
}

string GetHostName(){
    char hostname[1024];
    gethostname(hostname, sizeof(hostname)); // fetches the current hostname from the kernel
    return string(hostname);
}

string GetUserName(){
    const char *user = getenv("USER");
    if (user !=nullptr)
    {
        return string(user);
    }
   
        return "User not found.";
    
}

// System information structures
struct ProcessInfo {
    int pid;
    std::string name;
    std::string state;
    float cpu_usage;
    float memory_usage;
};
// Memory functions (mem.cpp)
struct MemoryInfo {
    unsigned long total_ram;
    unsigned long used_ram;
    unsigned long free_ram;
    unsigned long total_swap;
    unsigned long used_swap;
    unsigned long free_swap;
    unsigned long total_disk;
    unsigned long used_disk;
    unsigned long free_disk;
};

MemoryInfo GetMemoryInfo() {
    MemoryInfo info = {0};
    std::ifstream memfile("/proc/meminfo");
    std::string line;
    
    while(std::getline(memfile, line)) {
        std::istringstream iss(line);
        std::string key;
        unsigned long value;
        std::string unit;
        
        iss >> key >> value >> unit;
        
        if (key == "MemTotal:") {
            info.total_ram = value * 1024; // Convert KB to bytes
        } else if (key == "MemAvailable:") {
            info.free_ram = value * 1024;
        } else if (key == "SwapTotal:") {
            info.total_swap = value * 1024;
        } else if (key == "SwapFree:") {
            info.free_swap = value * 1024;
        }
    }
    
    info.used_ram = info.total_ram - info.free_ram;
    info.used_swap = info.total_swap - info.free_swap;
    
    // Get disk usage for root filesystem
    struct statvfs stat;
    if (statvfs("/", &stat) == 0) {
        info.total_disk = stat.f_blocks * stat.f_frsize;
        // info.free_disk = stat.f_avail * stat.f_frsize;
        info.used_disk = info.total_disk - info.free_disk;
    }
    
    return info;
}

float GetRAMUsagePercent() {
    MemoryInfo info = GetMemoryInfo();
    if (info.total_ram == 0) return 0.0f;
    return 100.0f * info.used_ram / info.total_ram;
}

float GetSwapUsagePercent() {
    MemoryInfo info = GetMemoryInfo();
    if (info.total_swap == 0) return 0.0f;
    return 100.0f * info.used_swap / info.total_swap;
}

float GetDiskUsagePercent() {
    MemoryInfo info = GetMemoryInfo();
    if (info.total_disk == 0) return 0.0f;
    return 100.0f * info.used_disk / info.total_disk;
}

std::string ReadProcessName(int pid) {
    std::ifstream commfile("/proc/" + std::to_string(pid) + "/comm");
    std::string name;
    if (commfile.is_open()) {
        std::getline(commfile, name);
    }
    return name.empty() ? "Unknown" : name;
}

std::string ReadProcessState(int pid) {
    std::ifstream statfile("/proc/" + std::to_string(pid) + "/stat");
    std::string line;
    if (std::getline(statfile, line)) {
        std::istringstream iss(line);
        std::string token;
        // Skip PID and command
        iss >> token >> token;
        // Third field is state
        iss >> token;
        return token;
    }
    return "?";
}

float ReadProcessCPU(int pid) {
    std::ifstream statfile("/proc/" + std::to_string(pid) + "/stat");
    std::string line;
    if (std::getline(statfile, line)) {
        std::istringstream iss(line);
        std::string token;
        
        // Skip to utime (14th field) and stime (15th field)
        for (int i = 0; i < 13; ++i) {
            iss >> token;
        }
        
        unsigned long utime, stime;
        iss >> utime >> stime;
        
        // Simple approximation - you might want to make this more accurate
        return (utime + stime) * 0.01f; // Very rough estimate
    }
    return 0.0f;
}

float ReadProcessMemory(int pid) {
    std::ifstream statusfile("/proc/" + std::to_string(pid) + "/status");
    std::string line;
    
    while(std::getline(statusfile, line)) {
        if (line.find("VmRSS:") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            unsigned long rss;
            iss >> key >> rss;
            
            // Get total memory to calculate percentage
            MemoryInfo meminfo = GetMemoryInfo();
            if (meminfo.total_ram > 0) {
                return 100.0f * (rss * 1024) / meminfo.total_ram;
            }
        }
    }
    return 0.0f;
}


std::vector<ProcessInfo> GetProcessList() {
    std::vector<ProcessInfo> processes;
    DIR* proc_dir = opendir("/proc");
    
    if (proc_dir == nullptr) {
        return processes;
    }
    
    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != nullptr) {
        // Check if directory name is a number (PID)
        if (strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
            int pid = std::atoi(entry->d_name);
            
            ProcessInfo proc;
            proc.pid = pid;
            proc.name = ReadProcessName(pid);
            proc.state = ReadProcessState(pid);
            proc.cpu_usage = ReadProcessCPU(pid);
            proc.memory_usage = ReadProcessMemory(pid);
            
            processes.push_back(proc);
        }
    }
    
    closedir(proc_dir);
    
    // Sort by CPU usage (descending)
    std::sort(processes.begin(), processes.end(), 
              [](const ProcessInfo& a, const ProcessInfo& b) {
                  return a.cpu_usage > b.cpu_usage;
              });
    
    return processes;
}
int main(int argc, char* argv[])
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER);
    const char *glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_Window* window = SDL_CreateWindow("System Info", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 700, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
   io.Fonts->AddFontFromFileTTF("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 20.0f);

    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_window = true;

    while (!SDL_QuitRequested())
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                show_window = false;
        }
        if (!show_window) break;

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        if (show_window)
        {
            ImGui::Begin("System Info", &show_window);

            // System Info
            ImGui::Text("OS: %s", GetOSName().c_str());
            ImGui::Text("Hostname: %s", GetHostName().c_str());
            ImGui::Text("User: %s", GetUserName().c_str());
            ImGui::Separator();
             ImGui::Separator();

            // Memory Info
            MemoryInfo mem = GetMemoryInfo();
            ImGui::Text("Memory Information:");
            ImGui::Text("This is cliff omollo");
            ImGui::BulletText("Total RAM: %lu MB", mem.total_ram / (1024 * 1024));
            ImGui::BulletText("Used RAM: %lu MB", mem.used_ram / (1024 * 1024));
            ImGui::BulletText("Free RAM: %lu MB", mem.free_ram / (1024 * 1024));
            ImGui::BulletText("RAM Usage: %.2f%%", GetRAMUsagePercent());
            ImGui::BulletText("Swap Usage: %.2f%%", GetSwapUsagePercent());
            ImGui::BulletText("Disk Usage: %.2f%%", GetDiskUsagePercent());
            ImGui::Separator();

            // Process Info
            ImGui::Text("Running Processes:");
            if (ImGui::BeginTable("ProcessTable", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable))
            {
                ImGui::TableSetupColumn("PID");
                ImGui::TableSetupColumn("Name");
                ImGui::TableSetupColumn("State");
                ImGui::TableSetupColumn("CPU %%");
                ImGui::TableSetupColumn("Memory %%");
                ImGui::TableHeadersRow();

                std::vector<ProcessInfo> processes = GetProcessList();
                int display_limit = 20; // Display only top 20 by CPU usage

                for (size_t i = 0; i < std::min(processes.size(), static_cast<size_t>(display_limit)); ++i)
                {
                    ImGui::TableNextRow();
                    ImGui::TableSetColumnIndex(0); ImGui::Text("%d", processes[i].pid);
                    ImGui::TableSetColumnIndex(1); ImGui::Text("%s", processes[i].name.c_str());
                    ImGui::TableSetColumnIndex(2); ImGui::Text("%s", processes[i].state.c_str());
                    ImGui::TableSetColumnIndex(3); ImGui::Text("%.2f", processes[i].cpu_usage);
                    ImGui::TableSetColumnIndex(4); ImGui::Text("%.2f", processes[i].memory_usage);
                }

                ImGui::EndTable();
            }

            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
