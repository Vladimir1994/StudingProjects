#include "BoardModel.h"

BoardModel::BoardModel():fieldSize_(10),winSize_(5)
{
    for (int i = 0; i < fieldSize_; i++) {
        for (int j = 0; j < fieldSize_; j++)
            board_[i][j] = noSign;
    }
}

bool BoardModel::makeMove(const int &x, const int &y, const signtype &sign)
{
    if ((x < fieldSize_) && (x >= 0) && (y < fieldSize_) &&
        (y >= 0) && (board_[x][y] == noSign)) {
        board_[x][y] = sign;
		return true;
    } else {
		return false;
    }
}

wintype BoardModel::isWin(const int &lastMoveX, const int &lastMoveO)
{
    signtype lastMove = board_[lastMoveX][lastMoveO];

	int count = 1;
	int sum = 1;
    while (((lastMoveX + count) < fieldSize_) &&
            (board_[lastMoveX][lastMoveO]
             == board_[lastMoveX + count][lastMoveO])) {
		count++;
		sum++;
    }

	count = 1;
    while (((lastMoveX - count) >= 0) &&
             (board_[lastMoveX][lastMoveO]
             == board_[lastMoveX - count][lastMoveO])) {
		count++;
		sum++;
    }
    if ((sum >= winSize_) && (lastMove == x))
        return xWin;
    if ((sum >= winSize_) && (lastMove == o))
        return oWin;

	count = 1;
	sum = 1;
    while (((lastMoveO + count) < fieldSize_) &&
            (board_[lastMoveX][lastMoveO]
            == board_[lastMoveX][lastMoveO + count])) {
		count++;
		sum++;
    }
	count = 1;
    while (((lastMoveO - count) >= 0) &&
            (board_[lastMoveX][lastMoveO]
            == board_[lastMoveX][lastMoveO - count])) {
		count++;
		sum++;
    }
    if ((sum >= winSize_) && (lastMove == x))
        return xWin;
    if ((sum >= winSize_) && (lastMove == o))
        return oWin;

	count = 1;
	sum = 1;
    while (((lastMoveO + count) < fieldSize_) && ((lastMoveX + count) < fieldSize_)
           && (board_[lastMoveX][lastMoveO]
                == board_[lastMoveX + count][lastMoveO + count])) {
		count++;
		sum++;
    }
	count = 1;
    while (((lastMoveO - count) >= 0)  && ((lastMoveX -count) >= 0) &&
            (board_[lastMoveX][lastMoveO]
             == board_[lastMoveX - count][lastMoveO - count])) {
		count++;
		sum++;
    }
    if ((sum >= winSize_) && (lastMove == x))
        return xWin;
    if ((sum >= winSize_) && (lastMove == o))
        return oWin;

	count = 1;
	sum = 1;
    while (((lastMoveO - count) >= 0) && ((lastMoveX + count) < fieldSize_)
           && (board_[lastMoveX][lastMoveO]
               == board_[lastMoveX + count][lastMoveO - count])) {
		count++;
		sum++;
    }
	count = 1;
    while (((lastMoveO - count) < fieldSize_)  && ((lastMoveX - count) >= 0)
           && (board_[lastMoveX][lastMoveO]
               == board_[lastMoveX - count][lastMoveO + count])) {
		count++;
		sum++;
    }
    if ((sum >= winSize_) && (lastMove == x))
        return xWin;
    if ((sum >= winSize_) && (lastMove == o))
        return oWin;

	count = 0;
    for (int i = 0; i < fieldSize_; i++) {
            for (int j = 0; j < fieldSize_; j++) {
                if (board_[i][j] == noSign)
					count++;
        }
    }
    if (count == 0) {
        return draw;
    } else {
        return noWin;
    }
}

int BoardModel::getSize() const
{
	return fieldSize_;
}

int BoardModel::getWinSize() const
{
	return winSize_;
}

signtype BoardModel::getCell(const int &x, const int &y)
{
    return board_[x][y];
}
