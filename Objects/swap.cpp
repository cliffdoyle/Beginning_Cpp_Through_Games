#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    srand(time(0)); // Seed the random number generator
    string str1="Alibaba";
    int length=str1.size();
    int index1 = rand() %length;
    int index2 = rand() % length;
    cout << "original string: " << str1 << endl;

    // Swap characters at index1 and index2
    char temp=str1[index1];
    str1[index1]=str1[index2];
    str1[index2] = temp;
    cout<< "After swapping characters at index " << index1 << " and " << index2 << ": " << str1 << endl;
    cout <<"temp character: " << temp << endl;
}