#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printHello()
{
    cout << "PrintHello: Starting task..." << endl;
    // Simulate a task that takes some time
    this_thread::sleep_for(chrono::seconds(28));
    cout << "PrintHello: Finished task!" << endl;
}

int main()
{
    thread myThread(printHello);
    cout << "Main: Doing other stuff..." << endl;
    myThread.join();//Wait for the thread to finish
    cout<< "Main:Done." << endl;
}