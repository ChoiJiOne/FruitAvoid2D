#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <stb/stb_image.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>

SDL_Texture* LoadTextureFromFile(SDL_Renderer* InRenderer, const std::string& InPath)
{
    int32_t Width = 0,  Height = 0, Channels = 0;
    uint8_t* Buffer = stbi_load(InPath.c_str(), &Width, &Height, &Channels, 0);

    if (!Buffer) return nullptr;

    uint32_t Format = (Channels == 3) ? SDL_PIXELFORMAT_RGB24 : SDL_PIXELFORMAT_RGBA32;
    int32_t Pitch = Width * Channels;

    SDL_Texture* Texture = SDL_CreateTexture(InRenderer, Format, SDL_TEXTUREACCESS_STATIC, Width, Height);

    if (!Texture)
    {
		stbi_image_free(Buffer);
		Buffer = nullptr;

        return nullptr;
    }

    SDL_UpdateTexture(Texture, nullptr, reinterpret_cast<const void*>(Buffer), Pitch);

    stbi_image_free(Buffer);
    Buffer = nullptr;

    return Texture;
}

void DrawSprite(SDL_Renderer* InRenderer, SDL_Texture* InTexture, int32_t InCenterX, int32_t InCenterY, int32_t InWidth, int32_t InHeight)
{
	SDL_Rect Rect = { 
        InCenterX - InWidth / 2, 
        InCenterY - InHeight / 2,
        InWidth, 
        InHeight
    };

	SDL_RenderCopy(InRenderer, InTexture, nullptr, &Rect);
}

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

    SDL_Renderer* Renderer = SDL_CreateRenderer(
        Window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    SDL_Texture* BGSprite = LoadTextureFromFile(Renderer, "D:\\Repository\\FruitAvoid2D\\Resource\\texture\\Beach.jpg");

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

        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
        SDL_RenderClear(Renderer);

        DrawSprite(Renderer, BGSprite, 500, 400, 1000, 800);

        SDL_RenderPresent(Renderer);
    }

    SDL_DestroyTexture(BGSprite);
    BGSprite = nullptr;

    SDL_DestroyRenderer(Renderer);
    Renderer = nullptr;

    SDL_DestroyWindow(Window);
    Window = nullptr;

    SDL_Quit();
    return 0;
}