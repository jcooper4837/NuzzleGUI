#ifndef _BOARD_H
#define _BOARD_H
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace QuickSDL;
using namespace std;

class Board : public GameEntity {

private:
     Timer* mTimer;
	 InputManager* mInput;

     Texture* mOne;
     Texture* mTwo;
     Texture* mThree;
     Texture* mFour;
     Texture* mFive;
     Texture* mSix;
     Texture* mSeven;
     Texture* mEight;
     Texture* mEmpty;

     int* matrix;
	 float* listX;
	 float* listY;
	 int moves;
	 

public:
     Board();
     ~Board();

     void Shuffle();

     bool isValid();

	 bool newGame();

     bool containsValue(vector<int> list, int value);

     bool isSolvable();

	 void output();

	 void shift(char m);

	 int getMoves();

     void Swap();

     void Update();

     void Render();
};

#endif // !_PLAYSIDEBAR_H