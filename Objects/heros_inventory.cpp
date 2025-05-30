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
    string arr2[5]={"potion", "elixir", "scroll"};
    arr2[3]="amulet"; // This line will cause an error because arr2 has only 3 elements.
    cout << "\nMy Items in arr2:\n";
    int size = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < size; ++i)
    {
        cout<<arr2[i]<<endl;
    }
}

/*
It’s often a good idea to define a constant for the number of elements in an
array. That’s what I did with MAX_ITEMS, which represents the maximum number
of items the hero can carry:
const int MAX_ITEMS = 10;
You declare an array much the same way you would declare any variable you’ve
seen so far: You provide a type followed by a name. In addition, your compiler
must know the size of the array so it can reserve the necessary memory space.
You can provide that information following the array name, surrounded by
square brackets. Here’s how I declare the array for the hero’s inventory:

string inventory[MAX_ITEMS];

The preceding code declares an array inventory of MAX_ITEMS string objects.
(Because MAX_ITEMS is 10, that means 10 string objects.)

Array indexing begins at 0, just as you saw with string objects. This means that the following
code defines a five-element array:
int highScores[5];
Valid position numbers are 0 through 4, inclusive. There is no element highScores[5]! An
attempt to access highScores[5] could lead to disastrous results, including a program crash.
*/