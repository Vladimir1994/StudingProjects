#include "BoardView.h"

#include <stdio.h>

BoardView::BoardView(BoardModel *board)
{
    myBoard_ = board;
}

void BoardView::Show()
{
    printf("%s", "_0123456789\n");
    for (int i = 0; i < myBoard_->getSize(); i++) {
        printf("%d", i);
        for (int j = 0; j < myBoard_->getSize(); j++) {
            if (myBoard_->getCell(i, j) == x)
                printf("%c", 'X');
            else if (myBoard_->getCell(i, j) == o)
                printf("%c", 'O');
            else if (myBoard_->getCell(i, j) == noSign)
                printf("%c", '+');
        }
        printf("%c \n", ' ');
    }
    printf("%c \n", ' ');
    printf("%c \n", ' ');
}

void BoardView::StartGame()
{
    int xO;
    int yO;
    int xX;
    int yX;
    Show();
    do {
        bool move_X;
        bool move_O;
        do {
            printf("%s", "x move \n");
            scanf("%d", &xX);
            scanf("%d", &yX);
            move_X = myBoard_->makeMove(xX, yX, x);
            if (move_X)
                Show();
            else
                printf("%s", "wrong move \n");
        }
        while (move_X == false);

        if (myBoard_->isWin(xX,yX) == noWin) {
            do {
                printf("%s", "o move \n");
                scanf("%d", &xO);
                scanf("%d", &yO);
                move_O = myBoard_->makeMove(xO, yO, o);
                if (move_O)
                    Show();
                else
                    printf("%s", "wrong move \n");
            }
            while (move_O == false);
        }
    }
    while ((myBoard_->isWin(xO, yO) == noWin)
           && (myBoard_->isWin(xX, yX) == noWin));

    wintype whoWiw = myBoard_->isWin(xO, yO);
    if (whoWiw == noWin)
        whoWiw = myBoard_->isWin(xX, yX);
    if (whoWiw == xWin)
        printf("%s", "x win");
    else if (whoWiw == oWin)
        printf("%s", "o win");
    else if (whoWiw == draw)
        printf("%s", "draw");
    else
        printf("%s", "strange shit");
}
