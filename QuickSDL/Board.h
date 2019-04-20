#ifndef _BOARD_H
#define _BOARD_H
#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace QuickSDL;
using namespace std;

class Board : public GameEntity {

private:
     Timer* mTimer;

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

public:
     Board();
     ~Board();

     void Shuffle();

     bool isValid();

     bool containsValue(vector<int> list, int value);

     bool isSolvable();

     void Swap();

     void Update();

     void Render();
};

#endif // !_PLAYSIDEBAR_H