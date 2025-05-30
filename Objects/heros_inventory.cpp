//While string objects provide a great way to work with a 
//sequence of characters arrays provide a way to work with elements of any type

#include <iostream>

#include <string>

using namespace std;

int main()
{
    const int MAX_ITEMS = 10;
    string inventory[MAX_ITEMS];
    cout << "Welcome to the Hero's Inventory!\n";
    cout << "You can carry up to " << MAX_ITEMS << " items.\n";
    
    int numItems = 0;
    inventory[numItems++] = "sword";
    inventory[numItems++] = "shield";
    inventory[numItems++]="armor";

    for (int i = 0; i < numItems;++i){
        cout << inventory[i]<<endl;
    }

    
    // cout << inventory << endl;
    cout << "\n The item name '"<<inventory[0] << "' has";
    cout<<inventory[0].size()<<"letters in it.\n";

    cout << "\n You find a healing potion.";

    if (numItems < MAX_ITEMS)
    {
        inventory[numItems++] = "healing potion";
    }
    else
    {
        cout << "You have too many items and can't carry another.";
    }

    cout << "My Items:\n";
    for (int i = 0; i < numItems;++i){
        cout << inventory[i] << endl;
    }

    cout << "\n You trade your sword for a battle axe";
    inventory[0] = "battle axe";
    cout << "\nMy Items:\n";
    
    for (int i = 0; i < numItems;++i){
        cout << inventory[i]<<endl;
    }
}