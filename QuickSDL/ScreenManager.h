#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "Board.h"


class ScreenManager {
private:
     enum SCREENS {start, play, howToPlay};

     static ScreenManager* sInstance;

     InputManager* mInput;

     StartScreen* mStartScreen;
     PlayScreen* mPlayScreen;

     SCREENS mCurrentScreen;

public: 

     static ScreenManager* Instance();
     static void Release();

     void Update();
     void Render();

private:
     ScreenManager();
     ~ScreenManager();

};


#endif
