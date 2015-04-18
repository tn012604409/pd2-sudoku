#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>

#define NOTHING_POSSIBLE -1023

void Sudoku::GiveQuestion()
{
	 srand((unsigned) time(NULL));
        //srand((unsigned)time(0));
        int change,j,temp=0;
        int o,w,t,f,v,x,s,e,n=0;
        int arr[10];                            //use array as number
        for(int num=0;num<9;num++)
                arr[num]=num+1;
        for(int i=9;i>0;i--)
        {
                change=rand()%i;        //select random numbers
                temp=arr[change];
                for(j=change;j<(i-1);j++)
                        arr[j]=arr[j+1];
                arr[i-1]=temp;
        }
        o=arr[0],w=arr[1],t=arr[2],f=arr[3],v=arr[4],x=arr[5],s=arr[6],e=arr[7],n=arr[8];
std::cout<<f<<' '<<w<<' '<<x<<' '<<e<<' '<<s<<' '<<t<<' '<<n<<' '<<v<<' '<<o<<" -1 -1 -1"<<'\n'
                 <<e<<' '<<s<<' '<<t<<' '<<n<<' '<<v<<' '<<o<<' '<<x<<' '<<w<<' '<<f<<" -1 -1 -1"<<'\n'
                 <<n<<' '<<v<<' '<<o<<' '<<x<<' '<<w<<' '<<f<<' '<<e<<' '<<s<<' '<<t<<" -1 -1 -1"<<'\n'
                 <<"-1 -1 -1 "<<o<<' '<<t<<' '<<w<<' '<<f<<' '<<e<<' '<<s<<' '<<n<<' '<<v<<' '<<x<<'\n'
                 <<"-1 -1 -1 "<<s<<' '<<e<<' '<<v<<' '<<o<<' '<<n<<' '<<x<<' '<<f<<' '<<w<<' '<<t<<'\n'
                 <<"-1 -1 -1 "<<f<<' '<<n<<' '<<x<<' '<<w<<' '<<t<<' '<<v<<' '<<e<<' '<<s<<' '<<o<<'\n'
                 <<o<<' '<<t<<' '<<s<<' '<<w<<' '<<f<<' '<<e<<' '<<"-1 -1 -1 "<<x<<' '<<n<<' '<<v<<'\n'
                 <<w<<' '<<e<<' '<<f<<' '<<v<<' '<<x<<' '<<n<<' '<<"-1 -1 -1 "<<o<<' '<<t<<' '<<s<<'\n'
                 <<x<<' '<<n<<' '<<v<<' '<<t<<' '<<o<<' '<<s<<' '<<"-1 -1 -1 "<<w<<' '<<e<<' '<<f<<'\n'
                 <<t<<' '<<o<<' '<<w<<' '<<"-1 -1 -1 "<<s<<' '<<f<<' '<<e<<' '<<v<<' '<<x<<' '<<n<<'\n'
                 <<s<<' '<<f<<' '<<e<<' '<<"-1 -1 -1 "<<v<<' '<<x<<' '<<n<<' '<<t<<' '<<o<<' '<<w<<'\n'
                 <<v<<' '<<x<<' '<<n<<' '<<"-1 -1 -1 "<<t<<' '<<o<<' '<<w<<' '<<s<<' '<<f<<' '<<e
                 <<std::endl;
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

