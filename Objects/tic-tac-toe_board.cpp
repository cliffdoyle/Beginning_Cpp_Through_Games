//Demonstration of multidimensional arrays using Tic-Tac-Toe Board
#include <iostream>

using namespace std;
// using namespace 

int main()
{
    const int ROWS = 3;
    const int COLUMNS = 3;
    char ticTacToeBoard[ROWS][COLUMNS] = {
        {'X', 'O', 'X'},
        {' ', 'X', 'X'},
        {'X', 'O', 'O'}
    };
    cout<<"Tic-Tac-Toe Board:\n";
    for (int i = 0; i < ROWS;++i)
    {
        for (int j = 0; j < COLUMNS;++j)
        {
            cout << ticTacToeBoard[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"\n 'X' moves to the empty space location.\n";
    ticTacToeBoard[1][0] = 'X'; // 'X' moves to the empty space

    cout << "Updated Tic-Tac-Toe Board:\n";
    for (int i = 0; i < ROWS;++i)
    {
        for (int j = 0; j < COLUMNS;++j)
        {
            cout<< ticTacToeBoard[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nThe game is over.\n 'X' wins!\n";
}
/*
It’s possible to simply declare a multidimensional array without initializing it. Here’s an example:
char chessBoard[8][8];
The preceding code declares an 8*8, two-dimensional character array, chessBoard. By the
way, multidimensional arrays aren’t required to have the same size for each dimension. The
following is a perfectly valid declaration for a game map represented by individual characters:
char map[12][20];
*/

//Indexing Multidimensional Arrays
/*
The next thing I do in the program is display the tic-tac-toe board. But before I
get into the details of that, I want to explain how to index an individual array
element. You index an individual element of a multidimensional array by
supplying a value for each dimension of the array. That’s what I do to place
an X in the array where a space was:
board[1][0] = ’X’;
The previous code assigns the character to the element at board[1][0] (which
was ’ ’). Then I display the tic-tac-toe board after the move the same way I
displayed it before the move.

By using a pair of nested for loops, I move through the two-dimensional array
and display the character elements as I go, forming a tic-tac-toe board.
*/
