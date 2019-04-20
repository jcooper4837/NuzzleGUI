#include "PlaySideBar.h"

PlaySideBar:: PlaySideBar() {
     mTimer = Timer::Instance();
     mAudio = AudioManager::Instance();

     mBackground = new Texture("black.png");
     mBackground->Parent(this);
     mBackground ->Pos(Vector2(12.0f, 280.0f));
     mBackground->Scale(Vector2(12.0f, 280.0f));

     mTitle = new Texture("titleboard.png");
     mTitle->Parent(this);
     mTitle->Pos(Vector2(490.0f, 50.0f));

     mTable = new Texture("table.png");
     mTable->Parent(this);
     mTable->Pos(Vector2(400.0f, 395.0f));


     mBestLabel = new Texture("Best", "emulator.ttf", 28, { 150, 0, 0 });//prints Best on the left corner
     mBestLabel->Parent(this);
     mBestLabel->Pos(Vector2(25.0f, 180.0f));

     mBestScoreBoard = new Scoreboard;
     mBestScoreBoard->Parent(this);
     mBestScoreBoard->Pos(Vector2(25.0f, 230.0f));

     mCurrentLabel = new Texture("Current", "emulator.ttf", 28, { 150, 0, 0 });//prints Current on the middle left corner
     mCurrentLabel->Parent(this);
     mCurrentLabel->Pos(Vector2(25.0f, 280.0f));
     
     mCurrentScoreBoard = new Scoreboard;
     mCurrentScoreBoard->Parent(this);
     mCurrentScoreBoard->Pos(Vector2(25.0f, 330.0f));

}

PlaySideBar::~PlaySideBar() {
     mTimer = NULL;
     mAudio = NULL;

     delete mBackground;
     mBackground = NULL;

     delete mBestLabel;
     mBestLabel = NULL;

     delete mCurrentLabel;
     mCurrentLabel = NULL;
     
     delete mBestScoreBoard;
     mBestScoreBoard = NULL;

     delete mTable;
     mTable = NULL;

     delete mTitle;
     mTitle = NULL;
     
     delete mCurrentLabel;
     mCurrentLabel = NULL;

}

void PlaySideBar::SetBestMove(int Score) {
     mBestScoreBoard->Score(Score);
}

void PlaySideBar::SetCurrentMove(int Score) {
     mCurrentScoreBoard->Score(Score);
}

void PlaySideBar::Update() {

}

void PlaySideBar::Render() {
     mBackground->Render();
     mTitle->Render();
     mBestLabel->Render();
     mTable->Render();

     mBestScoreBoard->Render();

     mCurrentLabel->Render();
     mCurrentScoreBoard->Render();
}