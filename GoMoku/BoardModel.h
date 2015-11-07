#ifndef _MODEL_
#define _MODEL_

enum signtype {_X_, _O_, NO_SIGN};
enum wintype {X_WIN, O_WIN, DRAW, NO_WIN};

class BoardModel {
public:
	BoardModel();
    bool MakeMove(const int &x, const int &y, const signtype &sign);
    int getSize() const;
    int getWinSize() const;
    wintype isWin(const int &LAST_MOVE_X, const int &LAST_MOVE_O);
    signtype getCell(const int &x, const int &y);

private:
    const int FIELD_SIZE;
    const int WIN_SIZE;
    signtype board[10][10];
};

#endif
