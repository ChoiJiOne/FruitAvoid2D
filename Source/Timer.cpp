#include "Timer.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Timer::~Timer()
{
}

float Timer::DeltaTime() const
{
	if (bIsStop_)
	{
		return 0.0f;
	}
	else
	{
		return static_cast<float>(CurrTime_ - PrevTime_) / 1000.0f;
	}
}

float Timer::TotalTime() const
{
	if (bIsStop_)
	{
		return static_cast<float>(StopTime_ - PausedTime_ - BaseTime_) / 1000.0f;
	}
	else
	{
		return static_cast<float>(CurrTime_ - PausedTime_ - BaseTime_) / 1000.0f;
	}
}

void Timer::Reset()
{
	uint64_t TickTime = SDL_GetTicks64();

	BaseTime_ = TickTime;
	PausedTime_ = 0ULL;
	StopTime_ = 0ULL;
	PrevTime_ = TickTime;
	CurrTime_ = TickTime;
}

void Timer::Start()
{
	if (bIsStop_)
	{
		uint64_t TickTime = SDL_GetTicks64();

		PausedTime_ += (TickTime - StopTime_);
		PrevTime_ = TickTime;
		StopTime_ = 0ULL;

		bIsStop_ = false;
	}
}

void Timer::Stop()
{
	if (!bIsStop_)
	{
		uint64_t TickTime = SDL_GetTicks64();

		StopTime_ = TickTime;

		bIsStop_ = true;
	}
}

void Timer::Tick()
{
	PrevTime_ = CurrTime_;
	CurrTime_ = SDL_GetTicks64();
}