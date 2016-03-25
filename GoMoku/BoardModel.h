#ifndef _MODEL_
#define _MODEL_

enum signtype {x, o, noSign};
enum wintype {xWin, oWin, draw, noWin};

class BoardModel 
{
public:
	BoardModel();
    bool makeMove(const int &x, const int &y, const signtype &sign);
    int getSize() const;
    int getWinSize() const;
    wintype isWin(const int &lastMoveX, const int &lastMoveO);
    signtype getCell(const int &x, const int &y);

private:
    const int fieldSize_;
    const int winSize_;
    signtype board_[10][10];
};

#endif
