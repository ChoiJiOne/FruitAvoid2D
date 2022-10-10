#include "GameEngine.h"

std::string GameEngine::RootDirectory_;

std::unique_ptr<WindowSystem> GameEngine::WindowSystem_ = nullptr;
std::unique_ptr<RenderSystem> GameEngine::RenderSystem_ = nullptr;
std::unique_ptr<InputSystem> GameEngine::InputSystem_ = nullptr;
std::unique_ptr<ResourceSystem> GameEngine::ResourceSystem_ = nullptr;

void GameEngine::Init()
{
	int32_t SDLFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS;
	
	CHECK((SDL_Init(SDLFlags) == 0), "failed to initialize SDL");

#if defined(DEBUG) || defined(RELEASE)
	CHECK((__argc > 1), "please insert root directory");
	RootDirectory_ = __argv[1];
#endif
}

void GameEngine::Quit()
{
	ResourceSystem_.reset();
	InputSystem_.reset();
	RenderSystem_.reset();
	WindowSystem_.reset();

	SDL_Quit();
}

WindowSystem& GameEngine::CreateWindowSystem(const std::string& InTitle, int32_t InPositionX, int32_t InPositionY, int32_t InWidth, int32_t InHeight, uint32_t InFlags)
{
	WindowSystem_ = std::make_unique<WindowSystem>(InTitle, InPositionX, InPositionY, InWidth, InHeight, InFlags);
	return *WindowSystem_.get();
}

RenderSystem& GameEngine::CreateRenderSystem(bool bIsAccelerated, bool bIsActiveVsync)
{
	RenderSystem_ = std::make_unique<RenderSystem>(WindowSystem_->GetWindow(), bIsAccelerated, bIsActiveVsync);
	return *RenderSystem_.get();
}

InputSystem& GameEngine::CreateInputSystem()
{
	InputSystem_ = std::make_unique<InputSystem>();
	return *InputSystem_.get();
}

ResourceSystem& GameEngine::CreateResourceSystem()
{
	ResourceSystem_ = std::make_unique<ResourceSystem>(WindowSystem_->GetWindow());
	return *ResourceSystem_.get();
}
