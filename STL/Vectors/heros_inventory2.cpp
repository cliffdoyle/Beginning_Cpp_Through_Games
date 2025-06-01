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


//Before using Vector, we include the file that contains its definition
//i.e #include <vector>
//All STL components live in the std namespace
//By using the statement using namespace std; we can use the components without prefixing them with std::
//The vector class is a template class, so we need to specify the type of elements it will hold
//In this case, we use vector<string> to create a vector that holds strings
//We can add elements to the vector using the push_back() method
//We can access elements in the vector using the subscript operator []
//We can modify elements in the vector by assigning a new value to them
//We can remove the last element from the vector using the pop_back() method
//We can check if the vector is empty using the empty() method
//We can clear all elements from the vector using the clear() method
//We can get the size of the vector using the size() method
//We can iterate through the vector using a for loop
//We can use unsigned int for the loop variable to avoid negative indices

//To declare a vector of your own, write vector followed by the type of 
//objects you want to use with the vector, followed by the name of the vector.