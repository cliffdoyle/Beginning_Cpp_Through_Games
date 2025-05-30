//for (initialization; test;action) {
  //statements;
// }
//Initialization is a statement that sets up some initial condition for the loop
//Test is a condition that is checked before each iteration of the loop
//Action is a statement that is executed after each iteration of the loop
// The loop continues until the test condition evaluates to false
#include <iostream>

using namespace std;

int main()
{
    cout<<"Counting forward:\n";
    for (int i = 0; i < 10;++i){
        cout <<i<< " ";
    }

    cout << "\n \n Counting with nested for loops:\n";
    const int Rows = 5;
    const int Columns = 7;
    //Nesting for loops
    //The outer loop executes its loop body Rows times
    //But it just happens that there's another for loop inside this loop, as a result
    //The inner loop executes in full for each iteration of the outer loop
    /* 1. The outer for loop declares i and initializes it to 0. Since i is less than
ROWS (5), the program enters the outer loop’s body.
2. The inner loop declares j and initializes it to 0. Since j is less than
COLUMNS (3), the program enters its loop body, sending the values of
i and j to cout, which displays 0, 0.
3. The program reaches the end of the body of the inner loop and
increments j to 1. Since j is still less than COLUMNS (3), the program
executes the inner loop’s body again, displaying 0, 1.
4. The program reaches the end of the inner loop’s body and increments j
to 2. Since j is still less than COLUMNS (3), the program executes the inner
loop’s body again, displaying 0, 2.
5. The program reaches the end of the inner loop’s body and increments j
to 3. This time, however, j is not less than COLUMNS (3) and the inner
loop ends.
6. The program finishes the first iteration of the outer loop by sending endl
to cout, ending the first row.
7. The program reaches the end of the outer loop’s body and increments i
to 1. Since i is less than ROWS (5), the program enters the outer loop’s
body again.
8. The program reaches the inner loop, which starts from the beginning
once again, by declaring and initializing j to 0. The program goes
through the process I described in Steps 2 through 7, displaying the second
row of the grid. This process continues until all five rows have been
displayed.
Again, the important thing to remember is that the inner loop is executed in full
for each iteration of the outer loop.
*/
    for(int i = 0;i < Rows;++i)
    {
        for (int j = 0; j < Columns;++j)
        {
            cout << i << "," << j << "  ";
        }
        cout << endl;
    }
}
