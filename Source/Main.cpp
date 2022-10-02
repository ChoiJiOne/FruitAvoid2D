#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0)
    {
        std::cout << "failed to initialize SDL2" << std::endl;
        return 0;
    }

    SDL_Window* Window = SDL_CreateWindow(
        "FruitAvoid2D",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000,
        800,
        SDL_WINDOW_SHOWN
    );

    bool bIsDone = false;
    SDL_Event Event;

    while (!bIsDone)
    {
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                bIsDone = true;
            }
        }
    }

    SDL_DestroyWindow(Window);
    Window = nullptr;

    SDL_Quit();
    return 0;
}