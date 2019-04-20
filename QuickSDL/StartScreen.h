#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H 

#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"

using namespace QuickSDL;

class StartScreen : public GameEntity{
private: 

     Timer* mTimer;
     InputManager* mInput;

     //Top bar entities 
     GameEntity * mTopBar;
     Texture * mPlayerOne;
     Texture * mHighScore;
     Texture * mPlayerTwo;
     Scoreboard* mPlayerOneScore;
     Scoreboard* mTopScore;
     Scoreboard* mPlayerTwoScore;

     //Logo entities 
     Texture* mLogo;
     AnimatedTexture* mAnimatedLogo;


     //play mode entites 
     GameEntity* mPlayMode;
     Texture* mHowToMode;
     Texture* mOnePlayerMode;
     Texture* mCursor;
     Vector2 mCursorStartPos;
     Vector2 mCursorOffset;
     int mSelectedMode;

     //Bottom Bar Entities 
     GameEntity* mBottomBar;
     Texture* mNamco;
     Texture* mDate;
     Texture* mRights;

     //Screen Animation
     Vector2 mAnimationStartPos;
     Vector2 mAnimationEndPos;
     float mAnimationTotalTime;
     float mAnitmationTimer;
     bool mAnimationDone;
    

public: 
     StartScreen();
     ~StartScreen();

     void ResetAnimation();
     int SelectedMode();

     void ChangeSelectedMode(int change);

     void Update();
     
     void Render();


};
#endif