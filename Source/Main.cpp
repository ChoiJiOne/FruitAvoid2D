#include <iostream>
#include <string>
#include <vector>

#include "WindowSystem.h"
#include "RenderSystem.h"
#include "InputSystem.h"

#include "Texture.h"
#include "Font.h"

#include <SDL2/SDL.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0)
    {
        std::cout << "failed to initialize SDL2" << std::endl;
        return 0;
    }

    WindowSystem Window("FruitAvoid2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
    RenderSystem Renderer(Window.GetWindow(), true, true);
    InputSystem Input;

	Texture BGSprite(Renderer.GetRenderer(), "D:\\ToyEngine\\FruitAvoid2D\\Resource\\texture\\Beach.jpg");
	Font font(Renderer.GetRenderer(), "D:\\ToyEngine\\FruitAvoid2D\\Resource\\font\\JetBrainsMono-Bold.ttf", 0x20, 0x7E, 32.0f);

    while (!Input.Tick())
    {
        Renderer.BeginFrame(Color::Black);

        Renderer.DrawTexture2D(BGSprite, Vec2i(500, 400), 1000, 800);
        Renderer.DrawText2D(font, L"Hello World!", Vec2i(500, 400), Color::Red);
        
        Renderer.EndFrame();
    }

    SDL_Quit();
    return 0;
}