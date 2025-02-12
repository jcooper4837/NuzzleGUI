#include "PlayScreen.h"
#include "Board.h"
#include "AnimatedTexture.h"

PlayScreen::PlayScreen() {
     mTimer = Timer::Instance();
     mInput = InputManager::Instance();

     mSideBar = new PlaySideBar();
     mSideBar->Parent(this);
     mSideBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.09f, Graphics::Instance()->SCREEN_HEIGHT*0.05f));
     mSideBar->SetBestMove(0);
     mSideBar->SetCurrentMove(0);
     
     mBoard = new Board();
     mBoard->Parent(this);
     mBoard->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.09f, Graphics::Instance()->SCREEN_HEIGHT*0.05f));
     
}

PlayScreen:: ~PlayScreen() {
     mTimer = NULL;
     mInput = NULL;

     delete mSideBar;
     mSideBar = NULL;

     delete mBoard;
     mBoard = NULL;

}

void PlayScreen::Update() {
	 
	 if (mBoard->newGame())
	 {
		 mBoard->Shuffle();
		 mSideBar->SetCurrentMove(0);
		 mSideBar->SetBestMove(mSideBar->getBest());
		 mSideBar->startTimer();
	 }
	 else if (mBoard->isValid())
	 {
		 if (mBoard->getMoves() < mSideBar->getBest())
		 {
			 mSideBar->SetBestMove(mBoard->getMoves());
			 mSideBar->setBest(mBoard->getMoves());
		 }
		 mSideBar->youWin();
	 }
	 else if (!mBoard->isValid())
	 {
		 mSideBar->endTimer();
	 }
	 //std::cout << mSideBar->getTime() << endl;
	 mSideBar->SetCurrentMove(mBoard->getMoves());
     mSideBar->Update();
     mBoard->Update();
}


void PlayScreen::Render() {
     mSideBar->Render();
     mBoard->Render();
}