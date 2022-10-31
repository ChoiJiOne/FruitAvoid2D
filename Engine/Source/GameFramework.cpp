#include "GameFramework.h"

GameFramework::~GameFramework()
{
	ToyEngine::Quit();
}

void GameFramework::Init()
{
	ToyEngine::Init();
}