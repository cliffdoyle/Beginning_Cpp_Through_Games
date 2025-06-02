#include <iostream>

#include <vector>
#include <string>
using namespace std;


int main()
{
    vector<string> invent;
    invent.push_back("knife");
    invent.push_back("panga");
    invent.push_back("stone");

    vector<string>::iterator iter;
    iter=invent.begin();
    cout << "Your items:\n";
    for (iter = invent.begin(); iter != invent.end(); ++iter)
    {
        cout << *iter << endl;
    }

    vector<string>::iterator  inserti = invent.insert(invent.begin()+1, "spear");
    cout<< "\nYou have added a new item: " << *inserti << endl;

      cout << "Your items:\n";
    for (iter = invent.begin(); iter != invent.end(); ++iter)
    {
        cout << *iter << endl;
    }
    
    cout << "You have " << invent.size() << " items.\n";

    iter=invent.begin() + 1; // Point to the second item (panga)
    vector<string>::iterator removed=invent.erase((iter)); // Remove the second item (panga)
    cout << "\nYou have removed an item.This is the item after it: " << *removed << endl;

    cout << "You have " << invent.size() << " items.\n";
}