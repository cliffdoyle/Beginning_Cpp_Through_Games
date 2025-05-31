//Demonstrates Vectors in CPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    cout << "You have " << inventory.size() << "items.\n";

    cout << "\nYour items:\n";

    for (unsigned int i = 0; i < inventory.size();++i)
    {
        cout << inventory[i] << endl;
    }
    cout << "\nYou trade your sword for a battle axe.";
    inventory[0] = "battle axe";

    cout << "\nYour items:\n";
for (unsigned int i = 0; i < inventory.size(); ++i)
{
cout << inventory[i] << endl;
}

cout << "\n Your shield is destroyed in a fierce battle.";
inventory.pop_back();

    cout << "\nYour items:\n";
for (unsigned int i = 0; i < inventory.size(); ++i)
{
cout << inventory[i] << endl;
}

cout << "\nYou were robbed of all of your possessions by a thief.";
inventory.clear();

if (inventory.empty())
{
    cout << "\n You have nothing.\n";
}
}