#include "GameFramework.h"

GameFramework::~GameFramework()
{
	GameEngine::Quit();
}

void GameFramework::Init()
{
	GameEngine::Init();
}
