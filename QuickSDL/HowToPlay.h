#ifndef _HOWTOPLAY_H
#define _HOWTOPLAY_H

#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"
#include "PlaySideBar.h"
#include <iostream>

using namespace QuickSDL;

class HowToPlay : public GameEntity {
private:
     Timer* mTimer;
     InputManager* mInput;

	 Texture* mScreen;
    
public:
     HowToPlay();
     ~HowToPlay();

     void Update();

     void Render();


};

#endif