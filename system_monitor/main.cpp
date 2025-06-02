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

int main(int argc, char* argv[])
{
    //Initialize SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER);
    const char *glsl_version="#version 130";
     SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_Window* window = SDL_CreateWindow("System Info", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader
    // gl3wInit();
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
     ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings backends
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool show_window = true;
    // Main loop
    while(!SDL_QuitRequested())
    {
        // Poll and handle events (inputs, window resize, etc.)
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                show_window = false;
            // exit(1);
        }
         if (!show_window) break;

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Show the system info window
        if (show_window)
        {
            ImGui::Begin("System Info", &show_window);
            ImGui::Text("OS: %s", GetOSName().c_str());
            ImGui::Text("Hostname: %s", GetHostName().c_str());
            ImGui::Text("User: %s", GetUserName().c_str());
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