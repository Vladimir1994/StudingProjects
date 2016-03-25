#ifndef _VIEW_
#define _VIEW_

#include "BoardModel.h"

class BoardView {
public:
    BoardView(BoardModel *board);
    void StartGame();

private:
    BoardModel *myBoard_;
    void Show();
};

#endif
