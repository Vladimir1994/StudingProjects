#include "BoardView.h"
#include <stdio.h>

BoardView::BoardView(BoardModel *board) {
	myBoard = board;
}

void BoardView::Show() {
    printf("%s", "_0123456789\n");
    for(int i = 0; i < myBoard->getSize(); i++) {
		printf("%d", i);
        for(int j = 0; j < myBoard->getSize(); j++) {
            if(myBoard->getCell(i, j) == _X_)
                printf("%c", 'X');
            else if(myBoard->getCell(i, j) == _O_)
                printf("%c", 'O');
            else if(myBoard->getCell(i, j) == NO_SIGN)
                printf("%c", '+');
		};
        printf("%c \n", ' ');
	};
    printf("%c \n", ' ');
    printf("%c \n", ' ');
}

void BoardView::StartGame() {
	int x_O;
	int y_O;
	int x_X;
	int y_X;
	Show();
	do {
		bool move_X;
		bool move_O;
        do {
			printf("%s", "x move \n");
			scanf("%d", &x_X); //Доделать так, чтоб все не ломалось при бредовом вводе.
			scanf("%d", &y_X);
			move_X = myBoard->MakeMove(x_X, y_X, _X_);
			if(move_X)
				Show();
			else
				printf("%s", "wrong move \n");
        }
        while(move_X == false);

        if(myBoard->isWin(x_X,y_X) == NO_WIN) {
			do{
				printf("%s", "o move \n");
				scanf("%d", &x_O);
				scanf("%d", &y_O);
				move_O = myBoard->MakeMove(x_O, y_O, _O_);
				if(move_O)
					Show();
				else
					printf("%s", "wrong move \n");
            }
            while(move_O == false);
        }
    }
    while((myBoard->isWin(x_O, y_O) == NO_WIN) && (myBoard->isWin(x_X, y_X) == NO_WIN));

    wintype WhoWin = myBoard->isWin(x_O, y_O);
	if(WhoWin == NO_WIN)
        WhoWin = myBoard->isWin(x_X, y_X);
	if(WhoWin == X_WIN)
		printf("%s", "x win");	
	else if (WhoWin == O_WIN)
		printf("%s", "o win");
	else if (WhoWin == DRAW)
		printf("%s", "draw");
	else
		printf("%s", "strange shit");
}
