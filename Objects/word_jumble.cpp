//The classic word jumble game where the player can ask 
//for a hint
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
        {
{"wall", "Do you feel you’re banging your head against something?"},
{"glasses", "These might help you see the answer."},
{"labored", "Going slowly, is it?"},
{"persistent", "Keep at it."},
{"jumble", "It’s what the game is all about."}

        };

        //pick a random word from the array
        srand(static_cast<unsigned int>(time(0)));
        int choice=(rand()% NUM_WORDS);//random number between 0 and NUM_WORDS-1
        string theWord = WORDS[choice][WORD];//word to guess
        string theHint=WORDS[choice][HINT];//hint for the word

        string jumble = theWord; // jumble the word
        int length = jumble.size();
        for (int i = 0; i < length; ++i)
        {
            int index1 = rand() % length;
            int index2 = rand() % length;

            //swap the characters at index1 and index2
            char temp = jumble[index1];
            jumble[index1] = jumble[index2];
            jumble[index2] = temp;
        }
        cout << "Welcome to the word jumble game!\n";
        cout << "Unscramble the letters to guess the word.\n";
        cout << "Enter your guess (or type 'hint' for a hint): ";
        cout << "Enter ’hint’ for a hint.\n";
        cout << "Enter ’quit’ to quit the game.\n\n";
        cout << "The jumble is: " << jumble;
        
        string guess;
        cout << "\nYour guess: ";
        cin>> guess;
        while(guess !=theWord && guess !="qui")
        {
            if (guess == "hint")
            {
                cout << "Hint: " << theHint << endl;
            }
            else
            {
                cout << "Sorry, that’s not it.\n";
            }
            cout << "Enter your guess (or type 'hint' for a hint): ";
            cin >> guess;
        }
        
        if (guess ==theWord)
        {
            cout << "Congratulations! You guessed the word: " << theWord << endl;
        }
        cout << "Thanks for playing the word jumble game!\n";

}