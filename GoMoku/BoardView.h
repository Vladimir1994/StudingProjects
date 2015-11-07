#include "BoardModel.h"

#ifndef _VIEW_
#define _VIEW_

class BoardView {
public:
	BoardView(BoardModel *board);
	void StartGame();

private:
    BoardModel *myBoard;
    void Show();
};

#endif
