/*
Examining Vector Growth
Although vectors grow dynamically as needed, every vector has a specific size.
When a new element added to a vector pushes the vector beyond its current size,
the computer reallocates memory and might even copy all of the vector elements
to this newly seized chunk of memory real estate. This can cause a performance
hit.


The most important thing to keep in mind about program performance is
whether or not you need to care. For example, vector memory reallocation
might not occur at a performance-critical part of your program. In that case, you
can safely ignore the cost of reallocation. Also, with small vectors, the
reallocation cost might be insignificant so, again, you can safely ignore it.
However, if you need greater control over when these memory reallocations
occur, you have it.

Using the capacity() Member Function
The capacity() vector member function returns the capacity of a vector—in
other words, the number of elements that a vector can hold before a program
must reallocate more memory for it. A vector’s capacity is not the same thing as
its size (the number of elements a vector currently holds). Here’s a code snippet
to help drive this point home:

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout<<"Creating a 10 element vector to hold scores.\n";
    vector<int> scores(10, 0);
    cout << "Vector size is:"<<scores.size() << endl;
    cout << "Vector capacity is:" << scores.capacity() << endl;

    cout << "Adding a score.\n";
scores.push_back(0); //memory is reallocated to accommodate growth
cout << "Vector size is :" << scores.size() << endl;
cout << "Vector capacity is:" << scores.capacity() << endl;

scores.push_back(20); //add another score
cout << "Adding another score.\n";
cout << "Vector size is :" << scores.size() << endl;
cout << "Vector capacity is:" << scores.capacity() << endl;

scores.pop_back(); //remove the last element
cout<<"Vector size is :" << scores.size() << endl;
cout << "Vector capacity is:" << scores.capacity() << endl;

cout << "Reserving more memory.\n";
scores.reserve(20); //reserve memory for 10 additional elements
cout<<"Vector size is :" << scores.size() << endl;
cout << "Vector capacity is:" << scores.capacity() << endl;
}

/*
Right after I declare and initialize the vector, this code reports that its size and
capacity are both 10. However, after an element is added, the code reports that
the vector’s size is 11 while its capacity is 20. That’s because the capacity of a
vector doubles every time a program reallocates additional memory for it. In this
case, when a new score was added, memory was reallocated, and the capacity of
the vector doubled from 10 to 20.

*/

/*
🚀 What Is reserve() in std::vector?
In C++, a std::vector grows dynamically—meaning, when you add more elements than it can hold, it automatically allocates more memory. This is convenient, but there's a hidden cost:
Every time the vector runs out of capacity and grows, it must:

Allocate new memory, often doubling in size.

Copy all existing elements to the new memory.

Free the old memory.

This reallocation process can be expensive and slow if it happens many times.

*/

/*
🌱 Why Use reserve()?
Calling reserve(n) tells the vector:

“Please make space for n elements now, even if I haven’t added them yet.”

That way:

You avoid multiple reallocations when adding many items later.

You control when memory allocation happens.

It can speed up your program because memory management is expensive.
*/

/*
vector<int> scores;
scores.reserve(1000);  // Reserve space for 1000 scores up front

for (int i = 0; i < 1000; ++i) {
    scores.push_back(i);  // No reallocations will happen here
}
Without reserve(), this loop might reallocate several times as the vector grows (from size 0 → 1 → 2 → 4 → 8 → 16 → …). With reserve(1000), all that overhead is avoided.
*/
