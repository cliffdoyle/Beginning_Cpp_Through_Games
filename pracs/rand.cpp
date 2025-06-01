#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(static_cast<unsigned int> (time(0))); // Seed the random number generator with the current time

    for (int i = 1; i < 7;++i){
        int randNumber = rand() % 40;
        cout << "the random number: " << randNumber << endl;
    }
}