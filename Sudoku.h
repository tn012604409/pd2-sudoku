//Header guard
#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

class Sudoku
{
public:
    void GiveQuestion();
    void ReadIn();
    int Solve();
    void Print();
private:
    char m_board[12][12];

    bool FindBlank(int &row, int &col) const;
    short GetPossibleNumber(int row, int col) const;
};

#endif // SUDOKU_H_INCLUDED

