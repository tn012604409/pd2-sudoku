#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>

#define NOTHING_POSSIBLE -1023

void Sudoku::GiveQuestion()
{
	int num;
	srand((unsigned) time(NULL));
	num=rand()%3+1;
	std::cout<<num<<std::endl;
	switch(num)
	{
	case 1:
	
	std::cout<<"4 2 6 8 7 3 9 5 1 -1 -1 -1"<<'\n'
		 <<"8 7 3 9 0 1 6 2 4 -1 -1 -1"<<'\n'
		 <<"9 5 1 6 2 4 8 7 3 -1 -1 -1"<<'\n'
		 <<"-1 -1 -1 1 3 2 4 8 7 9 5 6"<<'\n'
		 <<"-1 -1 -1 7 8 5 1 9 6 4 2 3"<<'\n'
		 <<"-1 -1 -1 4 9 6 2 3 5 8 7 1"<<'\n'
		 <<"1 3 7 2 4 8 -1 -1 -1 6 9 5"<<'\n'
		 <<"2 8 4 5 6 9 -1 -1 -1 1 3 7"<<'\n'
		 <<"6 9 5 3 1 7 -1 -1 -1 2 8 4"<<'\n'
		 <<"3 1 2 -1 -1 -1 7 4 8 5 6 9"<<'\n'
		 <<"7 4 8 -1 -1 -1 5 6 9 3 1 2"<<'\n'
		 <<"5 6 9 -1 -1 -1 3 1 2 7 4 8"<<std::endl;
	break;
	case 2:
	std::cout<<"hello"
		 <<std::endl;
	break;
	case 3:	  
	std::cout<<"hi"
		 <<std::endl;
	break;
	}
}

void Sudoku::ReadIn()
{
	int a;
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<12; j++)
		{
			std::cin>>a;
			m_board[i][j]=a;
		}
	}
}
int Sudoku::Solve()
{
	int row, col;
	char backup[12][12];

	// Number of solution
	int rnt=0;

	memcpy(backup, m_board, sizeof(m_board));

	if(FindBlank(row, col))
	{
		short possible_num=GetPossibleNumber(row, col);
		if(possible_num!=NOTHING_POSSIBLE)			//避免回傳值錯誤
		{
			for(int num=1; num<=9; num++)
			{
				if(possible_num&(1<<num))               //
				{
					m_board[row][col]=num;
					rnt+=Solve();
				}
			}
		}
	}
	else
	{	//std::cout<<1
		//	<<std::endl;
		Print();
		rnt=1;
	}

	memcpy(m_board, backup, sizeof(m_board));

	return rnt;
	//std::cout<<rnt;
	//std::cout<<std::endl;
}

void Sudoku::Print()
{	
	for(int i=0; i<12; i++)
	{
		for(int j=0; j<12; j++)
		{
			std::cout<<(int)m_board[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

bool Sudoku::FindBlank(int &row, int &col) const
{
	for(row=0; row<12; row++)
		for(col=0; col<12; col++)
			if(m_board[row][col]==0)
				return true;
	return false;
}

short Sudoku::GetPossibleNumber(int row, int col) const
{
	// "not" zero
	short possibility_row=~0,possibility_col=~0,possibility_square=~0;
	for(int i=0;i<12;i++)
		if(m_board[row][i]!=0&&m_board[row][i]!=-1)
			possibility_row&=~(1<<m_board[row][i]);

	for(int i=0;i<12;i++)
		if(m_board[i][col]!=0&&m_board[i][col]!=-1)
			possibility_col&=~(1<<m_board[i][col]);

	short square_r=row/3*3, square_c=col/3*3;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(m_board[square_r+i][square_c+j]!=0&&m_board[square_r+i][square_c+j]!=-1)
				possibility_square&=~(1<<m_board[square_r+i][square_c+j]);

	return possibility_col&possibility_row&possibility_square;
}

