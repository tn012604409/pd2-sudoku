#include <iostream>
#include <cstring>
#include "Sudoku.h"
#include <cstdlib>
#include<time.h>
#include<cstdio>


#define NOTHING_POSSIBLE -1023
Sudoku::Sudoku()
{
        rnt=0;
}
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
	std::cout<<f<<' '<<"0"<<' '<<"0"<<' '<<e<<' '<<s<<' '<<t<<' '<<n<<' '<<v<<' '<<o<<" -1 -1 -1"<<'\n'
                 <<"0"<<' '<<"0"<<' '<<t<<' '<<n<<' '<<v<<' '<<o<<' '<<x<<' '<<w<<' '<<f<<" -1 -1 -1"<<'\n'
                 <<n<<' '<<"0"<<' '<<"0"<<' '<<x<<' '<<"0"<<' '<<f<<' '<<e<<' '<<"0"<<' '<<t<<" -1 -1 -1"<<'\n'
                 <<"-1 -1 -1 "<<"0"<<' '<<t<<' '<<"0"<<' '<<"0"<<' '<<e<<' '<<"0"<<' '<<"0"<<' '<<v<<' '<<x<<'\n'
                 <<"-1 -1 -1 "<<s<<' '<<"0"<<' '<<"0"<<' '<<o<<' '<<n<<' '<<"0"<<' '<<f<<' '<<"0"<<' '<<t<<'\n'
                 <<"-1 -1 -1 "<<"0"<<' '<<n<<' '<<"0"<<' '<<w<<' '<<"0"<<' '<<v<<' '<<e<<' '<<"0"<<' '<<"0"<<'\n'
                 <<"0"<<' '<<"0"<<' '<<s<<' '<<"0"<<' '<<"0"<<' '<<e<<' '<<"-1 -1 -1 "<<x<<' '<<n<<' '<<v<<'\n'
                 <<w<<' '<<"0"<<' '<<"0"<<' '<<"0"<<' '<<"0"<<' '<<"0"<<' '<<"-1 -1 -1 "<<o<<' '<<t<<' '<<"0"<<'\n'
                 <<"0"<<' '<<"0"<<' '<<v<<' '<<"0"<<' '<<"0"<<' '<<s<<' '<<"-1 -1 -1 "<<w<<' '<<e<<' '<<"0"<<'\n'
                 <<"0"<<' '<<o<<' '<<"0"<<' '<<"-1 -1 -1 "<<"0"<<' '<<"0"<<' '<<e<<' '<<v<<' '<<x<<' '<<n<<'\n'
                 <<s<<' '<<"0"<<' '<<e<<' '<<"-1 -1 -1 "<<v<<' '<<"0"<<' '<<n<<' '<<"0"<<' '<<"0"<<' '<<"0"<<'\n'
                 <<"0"<<' '<<x<<' '<<"0"<<' '<<"-1 -1 -1 "<<"0"<<' '<<o<<' '<<"0"<<' '<<s<<' '<<"0"<<' '<<e
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

bool Sudoku::CheckUnity(int check_arr[])
{
        int arr_unity[9]; // counters
        for(int i=0; i<9; ++i)
                arr_unity[i] = 0; // initialize
        for(int i=0; i<9; ++i){
                ++arr_unity[check_arr[i]-1]; // count
                //std::cout<<check_arr[i]
                         //<<std::endl;
        }
        for(int i=0; i<9; ++i){
                //std::cout<<"hi"<<arr_unity[i]
                        // <<std::endl;
                if(arr_unity[i] != 1){ // all element
                        return false;
                        }
        }
return true;
}
bool Sudoku::isCorrect()
{
        int k=0;
        bool check_result;
        int check_arr[9];
        for(int j=0; j<12; j++) // check colums
        {
                k=0;
                for(int i=0; i<12; i++)
                        if(ans_board[i][j]!=-1){
                                check_arr[k] = ans_board[i][j];
                                k++;
                        }
                check_result = CheckUnity(check_arr);
                if(check_result == false){
                        return false;}
         }
        for(int i=0; i<12; i++) // check rows
        {
                k=0;
                for(int j=0; j<12; ++j)
                        if(ans_board[i][j]!=-1){
                                check_arr[k] = ans_board[i][j];
                                k++;
                }
         check_result = CheckUnity(check_arr);
                if(check_result == false){
                        return false;
                }
        }
        for(int square_r=0;square_r<4;square_r++){
                for(int square_c=0;square_c<4;square_c++){
                        for(int i=0;i<3;i++)
                        {
                                for(int j=0;j<3;j++){
                                        if(ans_board[square_r*3+i][square_c*3+j]!=-1)
                                                check_arr[i*3+j]=ans_board[square_r*3+i][square_c*3+j];
                                }
                        }
                        check_result =CheckUnity(check_arr);
                        if(check_result == false){
                                return false;}
                }
        }
        return true;
}
int Sudoku::SolveCheck()
{
        int row, col;
        char backup[12][12];

        // Number of solution
        //int rnt=0;

        memcpy(backup, m_board, sizeof(m_board));

        if(FindBlank(row, col))
        {
                short possible_num=GetPossibleNumber(row, col);
                if(possible_num!=NOTHING_POSSIBLE)
                {
                        for(int num=1; num<=9; num++)
                        {
                                if(possible_num&(1<<num))
                                {
                                        m_board[row][col]=num;
                                        rnt=SolveCheck();
                                        //if have not filled the last blank rnt will be zero
                                         if(rnt>1) //more than one solve
                                        {
                                        std::cout<<"2"<<std::endl;
                                        exit(0);
                                        }
                                }
                        }
                }
  }
        else
        {
                //rnt+=1;
                rnt++;          //if have filled the last blank

                if (rnt==1)
                {
                        memcpy(ans_board,m_board,sizeof(m_board));      //store the first solve
                }
        }
        memcpy(m_board, backup, sizeof(m_board));                       //go to the last blank

        return rnt;
}
void Sudoku::Solve()
{
        SolveCheck();
        if(isCorrect()==false)
        {
        //std::cout<<"haha"
                //<<std::endl;
        std::cout<<"0"
                <<std::endl;
                exit(0);
        }
        if(rnt==1)
        {
                std::cout<<1
                         <<std::endl;
                Print();
        }
        /*if(isCorrect()==false)
        {
        std::cout<<"0"
                <<std::endl;
                exit(0);
        }*/

}
void Sudoku::Print()
{
        for(int i=0; i<12; i++)
        {
                for(int j=0; j<12; j++)
                {
                        std::cout<<(int)ans_board[i][j]<<" ";
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

