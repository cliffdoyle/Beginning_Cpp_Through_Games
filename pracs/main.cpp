#include <iostream>

#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

enum jumbo{WORD, HINT, NUMBER_FIELDS};
const int NUM_WORDS = 5;

const string WORDS[NUM_WORDS][NUMBER_FIELDS] =
{
 {"wall", "Do you feel you’re banging your head against something?"},
{"glasses", "These might help you see the answer."},
{"labored", "Going slowly, is it?"},
{"persistent", "Keep at it."},
{"jumble", "It’s what the game is all about."}

};

srand(time(0));
int choice = rand() % NUM_WORDS;
string theWord = WORDS[choice][WORD];
string theHint = WORDS[choice][HINT];

//Jumble the word

string jumble = theWord;
int length = jumble.size();

for (int i = 0; i < length;++i)
{
    int index1 = rand() % length;
    int index2 = rand() % length;

    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
}

cout << "The jumbled word: " << jumble << endl;

string guess;
cout << "\n\nYour guess: ";
cin >> guess;

//Game loop
while(guess !=theWord && guess !="quit")
{
    if (guess=="hint")
    {
        cout << theHint;
    }
    else
    {
        cout << "Sorry, thats not it.";
    }
    cout << "\n\n Your guess:";
    cin >> guess;
}
if (guess==theWord)
{
    cout << "\nThat's it! You guessed it!\n";

}
else
{
    cout << "\nSorry to see you leave early mate.Next time then!\n";
}
cout << "\nThanks for playing\n";
}