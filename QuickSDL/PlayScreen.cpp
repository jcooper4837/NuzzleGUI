#include "PlayScreen.h"
#include "Board.h"
#include "AnimatedTexture.h"

PlayScreen::PlayScreen() {
     mTimer = Timer::Instance();
     mInput = InputManager::Instance();

     mSideBar = new PlaySideBar();
     mSideBar->Parent(this);
     mSideBar->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.09f, Graphics::Instance()->SCREEN_HEIGHT*0.05f));
     mSideBar->SetBestMove(30);
     mSideBar->SetCurrentMove(30);
     
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
     mSideBar->Update();
     mBoard->Update();
     
}


void PlayScreen::Render() {
     mSideBar->Render();
     mBoard->Render();
}