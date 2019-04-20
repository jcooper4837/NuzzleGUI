#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"
#include <chrono>
#include <sstream>
#include <string>
using namespace std::chrono;

class PlaySideBar : public GameEntity {

private:
     Timer* mTimer;
     AudioManager* mAudio;

     Texture* mBackground;

     Texture* mBestLabel;
     Texture* mCurrentLabel;
	 Texture* mWin;
     Texture* mTable;
     Texture* mTitle;
	 Texture* mTime;

     Texture* mBestScoreBoard;
     Scoreboard* mCurrentScoreBoard;
    
	 Uint32 startTime;
	 Uint32 endTime;

	 int best;
	 std::stringstream time;

public:
     PlaySideBar();
     ~PlaySideBar();

     void SetBestMove(int Score);

     void SetCurrentMove(int Score);

	 void youWin();

	 void startTimer();

	 void endTimer();

	 Uint32 getTime();

	 int getBest();

	 void setBest(int b);

     void Update();

     void Render();

};

#endif // !_PLAYSIDEBAR_H