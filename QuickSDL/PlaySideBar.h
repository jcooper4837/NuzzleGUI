#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

class PlaySideBar : public GameEntity {

private:
     Timer* mTimer;
     AudioManager* mAudio;

     Texture* mBackground;

     Texture* mBestLabel;
     Texture* mCurrentLabel;
     Texture* mTable;
     Texture* mTitle;

     Scoreboard* mBestScoreBoard;
     Scoreboard* mCurrentScoreBoard;
    

public:
     PlaySideBar();
     ~PlaySideBar();

     void SetBestMove(int Score);

     void SetCurrentMove(int Score);

     void Update();

     void Render();

};

#endif // !_PLAYSIDEBAR_H