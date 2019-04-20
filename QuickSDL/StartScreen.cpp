//NUZZLE 2019

#include "StartScreen.h"

StartScreen::StartScreen() {
     mTimer = Timer::Instance();
     mInput = InputManager::Instance();

     //top bar where Highscore is posted 
     mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));
     mPlayerOne = new Texture("1UP", "emulator.ttf", 28, {200,0,0});
     mHighScore = new Texture("High Score", "emulator.ttf", 28, { 200,0,0 });
     mPlayerTwo = new Texture("2UP", "emulator.ttf", 28, { 200,0,0 });
     mPlayerOneScore = new Scoreboard();
     mTopScore = new Scoreboard;
     mPlayerTwoScore= new Scoreboard;

     //
     mPlayerOne->Parent(mTopBar);
     mHighScore ->Parent(mTopBar);
     mPlayerTwo ->Parent(mTopBar);
     mPlayerOneScore->Parent(mTopBar);
     mTopScore->Parent(mTopBar);
     mPlayerTwoScore->Parent(mTopBar);

     mPlayerOne->Pos(Vector2(-Graphics::Instance()->SCREEN_WIDTH*0.38f, 0.0f));
     mHighScore->Pos(Vector2(-30.0f, 0.0f));
     mPlayerTwo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.35f, 0.0f));

     mPlayerOneScore->Pos(Vector2(-Graphics::Instance()->SCREEN_WIDTH*0.30f, 40.0f));
     mTopScore->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.05f, 40.0f));
     mPlayerTwoScore->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.45f, 40.0f));

     mTopScore->Score(30);

     mTopBar->Parent(this);
     
     //logo Entities 
     mLogo = new Texture("title.png", 0, 0, 590, 208);
     mAnimatedLogo = new  AnimatedTexture("title.png", 0, 0, 590, 208, 3, .5f, AnimatedTexture::vertical);

     mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.45f, Graphics::Instance()->SCREEN_HEIGHT*0.3f));
     mAnimatedLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.45f, Graphics::Instance()->SCREEN_HEIGHT*0.3f));

     mLogo->Parent(this);
     mAnimatedLogo->Parent(this);
     
     //play mode entites 
     mPlayMode = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
     mHowToMode = new Texture("HOW TO PLAY", "emulator.ttf", 32, { 230,230,230 });
     mOnePlayerMode = new Texture(" PLAY       ", "emulator.ttf", 32, { 230,230,230 });
     mCursor = new Texture("Cursor.png");

     mHowToMode->Parent(mPlayMode);
     mOnePlayerMode->Parent(mPlayMode);
     mCursor->Parent(mPlayMode);

     mOnePlayerMode->Pos(Vector2(-18.0f, -35.0f));
     mHowToMode->Pos(Vector2(0.0f, 35.0f));
     mCursor->Pos(Vector2(-245.0f, -35.0f));

     mPlayMode->Parent(this);

     mCursorStartPos = mCursor->Pos(local);
     mCursorOffset = Vector2(0.0f, 70.0f);
     mSelectedMode = 0;

     //Bottom Bar Entities
     mBottomBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.f, Graphics::Instance()->SCREEN_HEIGHT*0.7f));
     mNamco = new Texture("khyaco", "namco__.ttf", 34, {200,0,0});
     mDate = new Texture("2019 NUZZLE LTD.", "emulator.ttf", 28, { 230,230,230 });
     mRights = new Texture("ALL RIGHTS RESERVED", "emulator.ttf", 28, { 230,230,230 });

     mNamco->Parent(mBottomBar);
     mDate->Parent(mBottomBar);
     mRights->Parent(mBottomBar);

     mNamco->Pos(Vector2(485.0f,85.0f));
     mDate->Pos(Vector2(485.0f, 130.0f));
     mRights -> Pos(Vector2(485.0f, 190.0f));

     mBottomBar->Parent(this);
     
     //screen animation variables
     ResetAnimation();

}

StartScreen::~StartScreen() {
     //freeing topbar entities 
     delete mTopBar; 
     mTopBar = NULL;
     delete mPlayerOne;
     mPlayerOne = NULL;
     delete mPlayerTwo;
     mPlayerTwo = NULL;
     delete mHighScore;
     mHighScore = NULL;
     delete mPlayerOneScore;
     mPlayerOneScore = NULL;
     delete mTopScore;
     mTopScore = NULL;
     delete mPlayerTwoScore;
     mPlayerTwoScore = NULL;

     //free play mode entities 
     delete mPlayMode;
     mPlayMode = NULL;
     delete mHowToMode;
     mHowToMode = NULL;
     delete mOnePlayerMode;
     mOnePlayerMode = NULL;
     delete mCursor;
     mCursor = NULL;

     //free bottom bar entities 
     delete mBottomBar;
     mBottomBar = NULL;
     delete mNamco;
     mNamco = NULL;
     delete mDate;
     mDate = NULL;
     delete mRights;
     mRights = NULL;

     //freeing logo entities 
     delete mLogo;
     mLogo = NULL;
     delete mAnimatedLogo;
     mAnimatedLogo = NULL;

}

void StartScreen::ResetAnimation() {
     //screen animation variables
     mAnimationStartPos = Vector2(0.0f, Graphics::Instance()->SCREEN_HEIGHT);
     mAnimationEndPos = VEC2_ZERO;
     mAnimationTotalTime = 5.0f;
     mAnitmationTimer = 0.0f;
     mAnimationDone = false;

     Pos(mAnimationStartPos);
}

int StartScreen::SelectedMode() {
     return mSelectedMode;
}

void StartScreen::ChangeSelectedMode(int change) {
     mSelectedMode += change;
     if (mSelectedMode < 0)
          mSelectedMode = 1;
     else if (mSelectedMode > 1)
          mSelectedMode = 0;

     mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
}

void StartScreen::Update() {
     if (!mAnimationDone) {
          mAnitmationTimer += mTimer->DeltaTime();
          Pos(lerp(mAnimationStartPos, mAnimationEndPos, mAnitmationTimer / mAnimationTotalTime));
                    
          if (mAnitmationTimer >= mAnimationTotalTime)
               mAnimationDone = true;

          if(mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP))
               mAnitmationTimer = mAnimationTotalTime; 
     }
     else {
          mAnimatedLogo->Update();

          if (mInput->KeyPressed(SDL_SCANCODE_DOWN))
               ChangeSelectedMode(1);
          else if (mInput->KeyPressed(SDL_SCANCODE_UP))
               ChangeSelectedMode(-1);
     }
}

void StartScreen::Render() {
     mPlayerOne->Render();
     mPlayerTwo ->Render();
     mHighScore->Render();
     mPlayerOneScore->Render();
     mTopScore->Render();
     mPlayerTwoScore->Render();
     //logo
     if (!mAnimationDone)
          mLogo->Render();
     else
          mAnimatedLogo->Render();

     //selection render
     mHowToMode->Render();
     mOnePlayerMode->Render();
     mCursor->Render();

     //bottom bar
     mNamco->Render();
     mDate->Render();
     mRights->Render();
}