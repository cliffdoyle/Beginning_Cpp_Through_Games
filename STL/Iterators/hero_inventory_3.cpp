//Hero's Inventory 3.0
//Demonstrates the use of iterators to traverse a vector of strings
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

    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;

    cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end();++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nYou trade your sword for a battle axe.\n";
    myIterator=inventory.begin();
    *myIterator="battle axe";
    cout << "Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end();++iter)
    {
        cout << *iter << endl;
    }
    cout << "\n The item name '" << *myIterator << "'has";
    cout<<(*myIterator).size()<<"letters in it.\n";

    cout<<"\n The item name'"<<*myIterator<<"'has";
    cout << myIterator->size()<<"letteres in it.\n";

    cout << "\n You recover a crossbow from a slain enemy.";
    inventory.insert(inventory.begin(), "crossbow");

    cout <<"\n Your items:\n";
    for (iter = inventory.begin();iter !=inventory.end();++iter)
    {
        cout << *iter << endl;
    }
    cout << "\n Your armor is destroyed in a fierce battle.";
    inventory.erase(inventory.begin() + 2); // Remove the second item (armor)
    cout << "\n Your items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        cout << *iter << endl;
    }

}

// Important Notes:
//  1. The code uses iterators to traverse the vector,
// vector<string>::iterator myIterator;
//The line declares an iterator named myIterator for a 
//vector that contains string objects
//Container is a data structure that holds a collection of objects
//Iterators are values that identify a particular element in a container
//Given an iterator, you can access value of the element it points to.
//An iterator is not one of the elements, but a way
//to refer to one. Specifically, we can use an iterator to refer to an element in a container.
//That is I can stick the myIterator Post-it note on a specific element in inventory.
//Once i have done that I can access the element or even change it.

// vector<string>::const_iterator iter;
// The preceding line of code creates a constant iterator named iter for a
// Vector that contains string objects.A constant iterator is just like a regular iterator
// except that you can't use it to change the element to which it refers; the element must remain the constant.
//Think of a constant iterator as providing a read-only view of the elements in the vector.

/*
However, the iterator itself can change. This means you can move
iter all around the vector inventory as you see fit. You can’t, however, change
the value of any of the elements through iter. With a constant iterator the Postit
can change, but the thing it’s stuck to can’t.

Why would you want to use a constant iterator if it’s a limited version of a
regular iterator? First, it makes your intentions clearer. When you use a constant
iterator, it’s clear that you won’t be changing any element to which it refers.
Second, it’s safer. You can use a constant iterator to avoid accidentally changing
a container element. (If you attempt to change an element through a constant
iterator, you’ll generate a compile error.)

A call to inventory.end() returns an iterator one past the last element of the vector
The end() vector member function returns an iterator that’s one past the last element in
the vector—not the last element. Therefore, you can’t get a value from the iterator returned by
end(). This might seem counter-intuitive, but it works well for loops that move through a
container.

Altering an Iterator
The action statement in the loop, ++iter, increments iter, which moves it to the
next element in the vector. Depending upon the iterator, you can perform other
mathematical operations on iterators to move them around a container. Most
often, though, you’ll find that you simply want to increment an iterator.

Dereferencing an Iterator
In the loop body, I send *iter to cout. By placing the dereference operator (*) in
front of iter, I display the value of the element to which the iterator refers (not
the iterator itself). By placing the dereference operator in front of an iterator,
you’re saying, “Treat this as the thing that the iterator references, not as the
iterator itself.”

The vector converts the string literalls "sword", "armor", and "shield" into
string objects and stores them in the vector. The vector then holds three

*myIterator = "battle axe";
Remember, by dereferencing myIterator with *, the preceding assignment
statement says, “Assign "battle axe" to the element that myIterator references.”

Whenever you dereference an iterator to access a data member or member function, surround the
dereferenced iterator by a pair of parentheses. This ensures that the dot operator will be applied to
the object the iterator references.

Syntactic sugar is a nicer, alternative syntax. It replaces harsh syntax with something that’s a bit
easier to swallow. As an example, instead of writing the code (*myIterator).size(), I can
use the syntactic sugar provided by the -> operator and write myIterator->size().

Using the insert() Vector Member Function
Next I add a new item to the hero’s inventory. This time, though, I don’t add the
item to the end of the sequence; instead, I insert it at the beginning.
inventory.insert(inventory.begin(), "crossbow");
One form of the insert() member function inserts a new element into a vector
just before the element referred to by a given iterator. You supply two arguments to
this version of insert()—the first is an iterator, and the second is the element to
be inserted. In this case, I inserted "crossbow" into inventory just before the first
element. As a result, all of the other elements will move down by one. This version
of the insert() member function returns an iterator that references the newly
inserted element. In this case, I don’t assign the returned iterator to a variable.

Using the erase() Vector Member Function
Next I remove an item from the hero’s inventory. However, this time I don’t
remove the item at the end of the sequence; instead, I remove one from the middle.
inventory.erase((inventory.begin() + 2));
One form of the erase() member function removes an element from a vector.
You supply one argument to this version of erase()—the iterator that references
the element you want to remove. In this case, I passed (inventory.begin() + 2),
which is equal to the iterator that references the third element in inventory. This
removes the string object equal to "armor". As a result, all of the following
elements will move up by one. This version of the erase() member function
returns an iterator that references the element after the element that was
removed. In this case, I don’t assign the returned iterator to a variable.

Using the erase() Vector Member Function
Next I remove an item from the hero’s inventory. However, this time I don’t
remove the item at the end of the sequence; instead, I remove one from the middle.
inventory.erase((inventory.begin() + 2));
One form of the erase() member function removes an element from a vector.
You supply one argument to this version of erase()—the iterator that references
the element you want to remove. In this case, I passed (inventory.begin() + 2),
which is equal to the iterator that references the third element in inventory. This
removes the string object equal to "armor". As a result, all of the following
elements will move up by one. This version of the erase() member function
returns an iterator that references the element after the element that was
removed. In this case, I don’t assign the returned iterator to a variable.

*/