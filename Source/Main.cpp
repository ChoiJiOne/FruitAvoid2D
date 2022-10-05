#include <iostream>
#include <string>
#include <vector>

#include "Texture.h"
#include "Font.h"

#include <SDL2/SDL.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>

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

void DrawText(
	SDL_Renderer* InRenderer, 
	const std::wstring& InText, 
	int32_t InX, int32_t InY,
	Font& InAtlas,
	uint8_t InRed, 
	uint8_t InGreen, 
	uint8_t InBlue, 
	uint8_t InAlpha
)
{
	int32_t x = InX, y = InY;
	for (auto& Unicode : InText)
	{
		SDL_Texture* TextureAtlas = InAtlas.GetTextureAtlas();
		SDL_SetTextureColorMod(TextureAtlas, InRed, InGreen, InBlue);
		SDL_SetTextureAlphaMod(TextureAtlas, InAlpha);

		const stbtt_packedchar& CurrInfo = InAtlas.GetPackedchar(static_cast<int32_t>(Unicode));

		SDL_Rect Src =
		{
			CurrInfo.x0,
			CurrInfo.y0,
			CurrInfo.x1 - CurrInfo.x0,
			CurrInfo.y1 - CurrInfo.y0
		};

		SDL_Rect Dst =
		{
			x + CurrInfo.xoff,
			y + CurrInfo.yoff,
			(CurrInfo.x1 - CurrInfo.x0),
			(CurrInfo.y1 - CurrInfo.y0)
		};

		SDL_RenderCopy(InRenderer, TextureAtlas, &Src, &Dst);
		x += static_cast<int32_t>(CurrInfo.xadvance);
	}
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

	Texture BGSprite(Renderer, "D:\\ToyEngine\\FruitAvoid2D\\Resource\\texture\\Beach.jpg");

	int32_t BeginCodePoint = 0x20;
	int32_t EndCodePoint = 0x7E;
	float FontSize = 32.0f;
	Font font(Renderer, "D:\\ToyEngine\\FruitAvoid2D\\Resource\\font\\JetBrainsMono-Bold.ttf", BeginCodePoint, EndCodePoint, FontSize);

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

        DrawSprite(Renderer, BGSprite.GetTextureResource(), 500, 400, 1000, 800);
		DrawText(Renderer, L"Hello World!", 100, 100, font, 255, 255, 0, 255);
        
        SDL_RenderPresent(Renderer);
    }

	BGSprite.~Texture();
	font.~Font();

    SDL_DestroyRenderer(Renderer);
    Renderer = nullptr;

    SDL_DestroyWindow(Window);
    Window = nullptr;

    SDL_Quit();
    return 0;
}