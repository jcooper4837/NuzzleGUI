#ifndef _HOWTOPLAY_H
#define _HOWTOPLAY_H

#include "Timer.h"
#include "Texture.h"
#include "InputManager.h"

using namespace QuickSDL;

class HowToPlay : public GameEntity {
private:
     Timer* mTimer;
     InputManager* mInput;

    
public:
     HowToPlay();
     ~HowToPlay();

     void Update();

     void Render();


};

#endif