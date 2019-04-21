#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();

	mScreen = new Texture("howtoplay2.png");
	mScreen->Parent(this);
	mScreen->Pos(Vector2(450.0f, 400.0f));
}

HowToPlay::~HowToPlay()
{
	mTimer = NULL;
	mInput = NULL;

	delete mScreen;
	mScreen = NULL;
}

void HowToPlay::Update()
{
	
}

void HowToPlay::Render()
{
	mScreen->Render();
}