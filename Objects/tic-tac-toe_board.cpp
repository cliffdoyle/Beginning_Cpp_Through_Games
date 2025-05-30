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