#include <iostream>
#include <string>
#include <vector>

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

SDL_Texture* LoadFontFromFile(
	SDL_Renderer* InRenderer,
	const std::string& InPath,
	const int32_t& InBeginCodePoint,
	const int32_t& InEndCodePoint,
	const float& InFontSize,
	std::vector<stbtt_packedchar>& OutPackedchars
)
{
	stbtt_fontinfo Info;
	std::vector<uint8_t> Buffer;

	Buffer.resize(1 << 25);

	FILE* File = nullptr;
	fopen_s(&File, InPath.c_str(), "rb");

	fread(&Buffer[0], 1, 1 << 25, File);
	fclose(File);

	stbtt_InitFont(
		&Info,
		reinterpret_cast<const unsigned char*>(&Buffer[0]),
		stbtt_GetFontOffsetForIndex(reinterpret_cast<const unsigned char*>(&Buffer[0]), 0)
	);

	int32_t Size = 16;
	OutPackedchars.resize(InEndCodePoint - InBeginCodePoint + 1);

	int32_t Success = 0;
	stbtt_pack_context PackContext;
	std::unique_ptr<uint8_t[]> Bitmap = nullptr;

	for (int32_t TextureSize = 16; TextureSize < 8192; TextureSize *= 2)
	{
		Bitmap = std::make_unique<uint8_t[]>(TextureSize * TextureSize);
		Success = stbtt_PackBegin(&PackContext, Bitmap.get(), TextureSize, TextureSize, 0, 1, nullptr);
		stbtt_PackSetOversampling(&PackContext, 1, 1);

		Success = stbtt_PackFontRange(
			&PackContext,
			reinterpret_cast<const unsigned char*>(&Buffer[0]),
			0,
			InFontSize,
			InBeginCodePoint,
			static_cast<int>(OutPackedchars.size()),
			&OutPackedchars[0]
		);

		if (Success)
		{
			stbtt_PackEnd(&PackContext);
			Size = TextureSize;
			break;
		}
		else
		{
			stbtt_PackEnd(&PackContext);
			Bitmap.reset();
		}
	}

	auto pixels = std::make_unique<uint32_t[]>(Size * Size);
	SDL_Texture* TextureAtlas = SDL_CreateTexture(InRenderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, Size, Size);
	SDL_SetTextureBlendMode(TextureAtlas, SDL_BLENDMODE_BLEND);
	SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);

	for (int32_t index = 0; index < Size * Size; ++index)
	{
		pixels[index] = SDL_MapRGBA(format, 0xFF, 0xFF, 0xFF, Bitmap[index]);
	}

	SDL_UpdateTexture(TextureAtlas, nullptr, pixels.get(), Size * sizeof(uint32_t));
	SDL_FreeFormat(format);

	return TextureAtlas;
}

void DrawText(
    SDL_Renderer* InRenderer, 
    const std::wstring& InText, 
    int32_t InX,
    int32_t InY,
	SDL_Texture* InAtlas,
    const int32_t& InBeginCodePoint,
    const int32_t& InEndCodePoint,
    const std::vector<stbtt_packedchar>& InPackedchars
)
{
	int32_t x = InX, y = InY;
	for (auto& Unicode : InText)
	{
		int32_t CodePoint = static_cast<int32_t>(Unicode) - InBeginCodePoint;

		SDL_SetTextureColorMod(InAtlas, 255, 255, 255);
		SDL_SetTextureAlphaMod(InAtlas, 255);

		const stbtt_packedchar& CurrInfo = InPackedchars[CodePoint];

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

		SDL_RenderCopy(InRenderer, InAtlas, &Src, &Dst);
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

    SDL_Texture* BGSprite = LoadTextureFromFile(Renderer, "D:\\Repository\\FruitAvoid2D\\Resource\\texture\\Beach.jpg");

    int32_t BeginCodePoint = 0x20;
    int32_t EndCodePoint = 0x7E;
    float FontSize = 32.0f;
    std::vector<stbtt_packedchar> Packedchars;

	SDL_Texture* Atlas = LoadFontFromFile(
		Renderer,
		"D:\\Repository\\FruitAvoid2D\\Resource\\font\\JetBrainsMono-Bold.ttf",
		BeginCodePoint,
		EndCodePoint,
		FontSize,
		Packedchars
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

        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
        SDL_RenderClear(Renderer);

        DrawSprite(Renderer, BGSprite, 500, 400, 1000, 800);
		DrawText(Renderer, L"Hello World!", 100, 100, Atlas, BeginCodePoint, EndCodePoint, Packedchars);
        
        SDL_RenderPresent(Renderer);
    }

    SDL_DestroyTexture(Atlas);
    Atlas = nullptr;

    SDL_DestroyTexture(BGSprite);
    BGSprite = nullptr;

    SDL_DestroyRenderer(Renderer);
    Renderer = nullptr;

    SDL_DestroyWindow(Window);
    Window = nullptr;

    SDL_Quit();
    return 0;
}