#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    int SolveCheck();
    void Solve();
    void Print();
    bool isCorrect();
private:
    char m_board[12][12];
    char ans_board[12][12];
    bool CheckUnity(int check_arr[]);
    int rnt;
    int FillRow();
    int FillCol();
    int FillSqu();


    bool FindBlank(int &row, int &col) const;
    short GetPossibleNumber(int row, int col) const;
};

#endif // SUDOKU_H_INCLUDED
