#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("/proc/cpuinfo");
    string line;
    bool found = false;
    while (getline(file, line))
    {
        if (line.find("vendor_id") != string::npos)
        {
            cout << line << endl;
            found = true;
            break;
        }
       
    }

    if (!found)
    {
        cout << "CPU model name not found." << endl;
    }
    file.close();
}