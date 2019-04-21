#include "ScreenManager.h"
#include "PlayScreen.h"

ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager*ScreenManager::Instance(){
     if (sInstance == NULL)
          sInstance = new ScreenManager();

     return sInstance;
}

void ScreenManager::Release() {
     delete sInstance;
     sInstance = NULL;

}
ScreenManager::ScreenManager() {
     mInput = InputManager::Instance();
     
     mStartScreen = new StartScreen();
     mPlayScreen = new PlayScreen();
	 mHowToPlay = new HowToPlay();
     mCurrentScreen = start;

}
ScreenManager::~ScreenManager() {
     mInput = NULL;
     
     delete mStartScreen;
     mStartScreen = NULL;

     delete mPlayScreen;
     mPlayScreen = NULL;

	 delete mHowToPlay;
	 mHowToPlay = NULL;
}

void ScreenManager::Update() {
     switch (mCurrentScreen) {

     case start:
          mStartScreen->Update();
          if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {//once enter key is pressed reset the animation and go to the play screen
			  if (mStartScreen->SelectedMode() == 0)
			  {
				  mCurrentScreen = play;
				  mStartScreen->ResetAnimation();
			  }
			  else if (mStartScreen->SelectedMode() == 1)
			  {
				  mCurrentScreen = howToPlay;
				  mStartScreen->ResetAnimation();
			  }
          }
          break;
     
     case play:
          mPlayScreen->Update();
          if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {//once ESC key is pressed go to the menu
               mCurrentScreen = start;
			   mPlayScreen = new PlayScreen();
          }

          break;

	 case howToPlay:
		 mHowToPlay->Update();
		 if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {//once ESC key is pressed go to the menu
			 mCurrentScreen = start;
		 }
		 break;
     }
}
void ScreenManager::Render() {
     switch (mCurrentScreen) {

     case start:
          mStartScreen->Render();
          
          break;
     case play:
          mPlayScreen->Render();

          break;

	 case howToPlay:
		  mHowToPlay->Render();
     }
}