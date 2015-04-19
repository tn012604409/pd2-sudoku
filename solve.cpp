#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>
#include<cstdio>
main()
{
	Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	return 0;

}
