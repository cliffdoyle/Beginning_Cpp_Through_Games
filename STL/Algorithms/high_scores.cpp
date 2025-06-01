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