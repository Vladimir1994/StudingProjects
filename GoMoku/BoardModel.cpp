#include "BoardModel.h"

BoardModel::BoardModel():FIELD_SIZE(10),WIN_SIZE(5){
	for(int i = 0; i < FIELD_SIZE; i++){
		for(int j = 0; j < FIELD_SIZE; j++){
			board[i][j] = NO_SIGN;
		};
	};
}

bool BoardModel::MakeMove(const int &x, const int &y, const signtype &sign){
    if ((x < FIELD_SIZE) && (x >= 0) && (y < FIELD_SIZE) &&
        (y >= 0) && (board[x][y] == NO_SIGN)){
		board[x][y] = sign;
		return true;
	}
	else{
		return false;
	};
}

wintype BoardModel::isWin(const int &LAST_MOVE_X, const int &LAST_MOVE_O){
	signtype LAST_MOVE = board[LAST_MOVE_X][LAST_MOVE_O];
	//поиск по горизонтали
	int count = 1;
	int sum = 1;
    while(((LAST_MOVE_X + count) < FIELD_SIZE) &&
        (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X + count][LAST_MOVE_O])){
		count++;
		sum++;
	};
	count = 1;
    while(((LAST_MOVE_X - count) >= 0) &&
        (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X - count][LAST_MOVE_O])){
		count++;
		sum++;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _X_)){
		return X_WIN;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _O_)){
		return O_WIN;
	};
	//по вертикали
	count = 1;
	sum = 1;
    while(((LAST_MOVE_O + count) < FIELD_SIZE) &&
        (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X][LAST_MOVE_O + count])){
		count++;
		sum++;
	};
	count = 1;
    while(((LAST_MOVE_O - count) >= 0) &&
        (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X][LAST_MOVE_O - count])){
		count++;
		sum++;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _X_)){
		return X_WIN;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _O_)){
		return O_WIN;
	};
	//по диагонали 1
	count = 1;
	sum = 1;
    while(((LAST_MOVE_O + count) < FIELD_SIZE) && ((LAST_MOVE_X + count) < FIELD_SIZE)
        && (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X + count][LAST_MOVE_O + count])){
		count++;
		sum++;
	};
	count = 1;
    while(((LAST_MOVE_O - count) >= 0)  && ((LAST_MOVE_X -count) >= 0) &&
        (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X - count][LAST_MOVE_O - count])){
		count++;
		sum++;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _X_)){
		return X_WIN;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _O_)){
		return O_WIN;
	};
	//по диагонали 2
	count = 1;
	sum = 1;
    while(((LAST_MOVE_O - count) >= 0) && ((LAST_MOVE_X + count) < FIELD_SIZE)
        && (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X + count][LAST_MOVE_O - count])){
		count++;
		sum++;
	};
	count = 1;
    while(((LAST_MOVE_O - count) < FIELD_SIZE)  && ((LAST_MOVE_X - count) >= 0)
        && (board[LAST_MOVE_X][LAST_MOVE_O] == board[LAST_MOVE_X - count][LAST_MOVE_O + count])){
		count++;
		sum++;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _X_)){
		return X_WIN;
	};
	if((sum >= WIN_SIZE) && (LAST_MOVE == _O_)){
		return O_WIN;
	};
	count = 0;
	for(int i = 0; i < FIELD_SIZE; i++){
			for(int j = 0; j < FIELD_SIZE; j++){
				if(board[i][j] == NO_SIGN){
					count++;
				};
		};
	};
	if (count == 0){
		return DRAW;
	}
	else{
		return NO_WIN;
	};
}

int BoardModel::getSize() const {
	return FIELD_SIZE;
}

int BoardModel::getWinSize() const {
	return WIN_SIZE;
}

signtype BoardModel::getCell(const int &x, const int &y) {
	return board[x][y];
}
