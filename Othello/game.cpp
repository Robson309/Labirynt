#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

	//! gloabal variables

	 int BLACK =1;
	 int WHITE =-1;
	 int EMPTY =0;
	
	 int WIDTH = 480;

	 bool direction[8];
	 int UP = 0;
	 int DOWN = 1;
	 int LEFT = 2;
	 int RIGHT = 3;
	 int UPLEFT = 4;
	 int UPRIGHT = 5;
	 int DOWNRIGHT = 6;
	 int DOWNLEFT = 7;

	 int turn;
	 int stone[8][8];
	 int counter_black = 0;
	 int counter_white = 0;

	 void initialState();
	 void countStone();
	 bool checkStone(int column, int row, int color);
	 bool checkAll(int turn);
	 void endGame();
	 void paintBoard();


int main(int argc, char** argv[])
{
	 
	void initialState();	
	countStone();
	turn = BLACK;


	system("PAUSE");
	return 0;
}

void initialState() {
	//stan poczatkowy 
	 for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			stone[i][j] = EMPTY;
       }
    }
    stone[3][3] = BLACK; stone[4][3] = WHITE;
    stone[3][4] = WHITE; stone[4][4] = BLACK;

}

void countStone() {
     
    for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(stone[i][j] == BLACK) counter_black++;
			if(stone[i][j] == WHITE) counter_white++;
		}
	}

	if (counter_black + counter_white == 64) endGame();
}

void endGame() {
    if (counter_black > counter_white) cout<<"Wygra³y czarne";
     else if (counter_black < counter_white) cout<<"Wygra³y bia³e";
     else cout<<"Remis";
}

bool checkAll(int turn) {
    for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(checkStone(i, j, turn)) return true;
		}
    }
    return false;
}

bool checkStone(int column, int row, int color){    
    int i, j;
    
    for (i = 0; i < 8; i++){
      direction[i] = false;
    }
    
    if(stone[column][row] != 0) return false;
		else { 
			if (column > 1 && stone[column-1][row] == -color) {
				for (i = column-2; i > 0 && stone[i][row] == -color; i--);
			if (stone[i][row] == color)  direction[LEFT] = true;
			}
      
			if (column < 6 && stone[column+1][row] == -color) {
				for (i = column+2; i < 7 && stone[i][row] == -color; i++);
			if (stone[i][row] == color) direction[RIGHT] = true;

			} 
      
			if (row > 1 && stone[column][row-1] == -color) {
				for (j = row-2; j > 0 && stone[column][j] == -color; j--);
			if (stone[column][j] == color) direction[UP] = true;
	
			}
      
			if (row < 6 && stone[column][row+1] == -color) {
				for (j = row+2; j < 7 && stone[column][j] == -color; j++);
			if (stone[column][j] == color) direction[DOWN] = true;
	
			}
      
			if (column > 1 && row > 1 && stone[column-1][row-1] == -color) {
				for (i = column-2, j = row-2; i > 0 && j > 0 && stone[i][j] == -color; i--, j--);
					if (stone[i][j] == color) direction[UPLEFT] = true;
			}

			if (column < 6 && row > 1 && stone[column+1][row-1] == -color) {
				for (i = column+2, j = row-2; i < 7 && j > 0 && stone[i][j] == -color; i++, j--);
			if (stone[i][j] == color) direction[UPRIGHT] = true;
	
			}

			if (column < 6 && row < 6 && stone[column+1][row+1] == -color) {
				for (i = column+2, j = row+2; i < 7 && j < 7 && stone[i][j] == -color; i++, j++);
			if (stone[i][j] == color) direction[DOWNRIGHT] = true;
			}
      
			if (column > 1 && row < 6 && stone[column-1][row+1] == -color) {
				for (i = column-2, j = row+2; i > 0 && j < 7 && stone[i][j] == -color; i--, j++);
			if (stone[i][j] == color) direction[DOWNLEFT] = true;
			} 

      
			for (i = 0; i < 8; i++){
				if (direction[i] == true){
				return true;
				}
			}

		return false;
		}
  }