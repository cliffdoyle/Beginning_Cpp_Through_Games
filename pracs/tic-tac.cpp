#include <iostream>
using namespace std;

//K15UMU57UD3N7

int main()
{
    char board[3][3] =
    {
        {'X','O','X'},
        {'O','X','O'},
        {'X','O',' '}
        };

    cout << "\nthe current board\n";

    for (int i = 0; i < 3;++i)
    {
        for (int j = 0; j < 3;++j)
        {
            cout << board[i][j]<<" ";
        }
        cout << endl;
    }

    board[2][2] = 'X';

    if (board[2][2]=='X')
    {
        cout << "You win\n";
    }

    cout << "New board format\n";

    for (int i = 0; i < 3;++i)
    {
        for (int j = 0; j < 3;++j)
        {
            cout << board[i][j]<<" ";
        }
        cout << endl;
    }


}