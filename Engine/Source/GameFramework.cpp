#include "GameFramework.h"
#include "ToyEngine.h"

GameFramework::~GameFramework()
{
	ToyEngine::Quit();
}

void GameFramework::Init()
{
	ToyEngine::Init();
}