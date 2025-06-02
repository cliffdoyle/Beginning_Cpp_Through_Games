#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h> // for gethostname
#include <cstdlib>

using namespace std;

int main()
{
    ifstream osfile("/etc/os-release");
    string line;
    bool found = false;

    while(getline(osfile,line))
    {
        if (line.find("PRETTY_NAME") !=std::string::npos)
        {
            cout << "OS:" << line.substr(line.find("=") + 1) << "\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "OS type not found." << endl;
    }
    osfile.close();

    char hostname[1024];
gethostname(hostname, sizeof(hostname));//fetches the current hostname from the kernel
std::cout << "Hostname: " << hostname << std::endl;

char* user = getenv("USER");
if (user != nullptr) {
    std::cout << "User: " << user << std::endl;
}


    return 0;
}