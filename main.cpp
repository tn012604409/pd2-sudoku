#include <iostream>
#include "Sudoku.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sudoku mySudoku;
    mySudoku.GiveQuestion();
    mySudoku.ReadIn();
    mySudoku.Solve();
}





/*#include <iostream>
#include "Sudoku.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sudoku mySudoku;
    mySudoku.GiveQuestion();
    mySudoku.ReadIn();
    mySudoku.Solve();
}*/

