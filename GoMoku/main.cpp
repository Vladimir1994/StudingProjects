/*
* Пример использования паттернов
* MVC.
*/


#include "BoardView.h"
#include "BoardModel.h"

int main(){
	BoardModel b;
	BoardView v(&b);
	v.StartGame();
	return 0;
}
