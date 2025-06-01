//High Scores
//Demonstrates algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int>::const_iterator iter;
    cout << "Creating a list of scores";

    vector<int>scores;
    scores.push_back(2000);
    scores.push_back(3999);
    scores.push_back(4669);
     scores.push_back(49);
      scores.push_back(899);

    cout << "\n High Scores:\n";
    for (iter = scores.begin(); iter != scores.end();++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nFinding a score.";
    int score;
    cout << "\n Enter a score to find:";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);

    if (iter !=scores.end())
    {
        cout << "\nScore found.\n";
    }
    else
    {
        cout << "Score not found. \n";
    }

    cout << "\n Randomizing scores.";
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scores.begin(), scores.end());

    cout << "\n Scores now\n";

    for (iter = scores.begin(); iter != scores.end();++iter)
    {
        cout << *iter << endl;
    }

    cout << "\nSorting scores.";
    sort(scores.begin(), scores.end());
    for (int i : scores)
    {
        cout << i << " ";
    }
    cout << endl;
}

/*
All STL components live in the std namespace. By using the statement using namespace std; we can use the components without prefixing them with std::.
Using the find() Algorithm
After I display the contents of the vector scores, I get a value from the user to
find and store it in the variable score. Then I use the find() algorithm to search
the vector for the value:
iter = find(scores.begin(), scores.end(), score);
The find() STL algorithm searches a specified range of a container’s elements
for a value. It returns an iterator that references the first matching element. If no
match is found, it returns an iterator to the end of the range. You must pass the
starting point as an iterator, the ending point as an iterator, and a value to find.
The algorithm searches from the starting iterator up to but not including the
ending iterator.

iter will reference the first occurrence of score in the vector, if the
value was found. So, as long as iter is not equal to scores.end(), I know that
score was found and I display a message saying so. Otherwise, iter will be equal
to scores.end() and I know score was not found.

Using the random_shuffle() Algorithm
Next I prepare to randomize the scores using the random_shuffle() algorithm.
Just as when I generate a single random number, I seed the random number
generator before I call random_shuffle(), so the order of the scores might be
different each time I run the program.
srand(static_cast<unsigned int>(time(0)));
Then I reorder the scores in a random way.
random_shuffle(scores.begin(), scores.end());

A very cool property of STL algorithms is that they can work with containers defined outside of the
STL. These containers only have to meet certain requirements. For example, even though string
objects are not part of the STL, you can use appropriate STL algorithms on them. The following
code snippet demonstrates this:
string word = "High Scores";
random_shuffle(word.begin(), word.end());
The preceding code randomly shuffles the characters in word. As you can see, string objects
have both begin() and end() member functions, which return iterators to the first character
and one past the last character, respectively. That’s part of the reason why STL algorithms work
with strings—because they’re designed to.

*/