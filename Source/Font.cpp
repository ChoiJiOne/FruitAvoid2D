#include "Font.h"

// @third party code - BEGIN SDL2
#include <SDL2/SDL.h>
// @third party code - END

Font::Font(
	SDL_Renderer* InRenderer, 
	const std::string& InPath, 
	int32_t InBeginCodePoint, 
	int32_t InEndCodePoint, 
	float InFontSize
) : BeginCodePoint_(InBeginCodePoint), 
	EndCodePoint_(InEndCodePoint)
{
	std::vector<uint8_t> Buffer;
	CHECK((LoadTrueTypeFontFromFile(InPath, Buffer)), "failed to load trye type font");

	stbtt_fontinfo Info;
	CHECK((stbtt_InitFont(
		&Info,
		reinterpret_cast<const unsigned char*>(&Buffer[0]),
		stbtt_GetFontOffsetForIndex(reinterpret_cast<const unsigned char*>(&Buffer[0]), 0)
	) != 0), "failed to initialize stb_truetype");

	int32_t BitmapSize = 0;
	std::shared_ptr<uint8_t[]> Bitmap = GenerateTextureAtlasBitmap(Buffer, BeginCodePoint_, EndCodePoint_, InFontSize, Packedchars_, BitmapSize);

	TextureAtlas_ = CreateTextureAtlasFromBitmap(InRenderer, Bitmap, BitmapSize);
}

Font::~Font()
{
    if (TextureAtlas_)
    {
        SDL_DestroyTexture(TextureAtlas_);
        TextureAtlas_ = nullptr;
    }
}

const stbtt_packedchar& Font::GetPackedchar(int32_t InCodePoint)
{
	CHECK(HasCodePointInRange(InCodePoint), "code point is out of range");
	int32_t Index = InCodePoint - BeginCodePoint_;
	return Packedchars_[Index];
}

bool Font::HasCodePointInRange(int32_t InCodePoint)
{
	return (BeginCodePoint_ <= InCodePoint) && (InCodePoint <= EndCodePoint_);
}

void Font::MeasureText(const std::wstring& InText, int32_t& OutWidth, int32_t& OutHeight)
{
	int32_t TextHeight = -1;
	int32_t TextWidth = 0;

	for (const auto& Unicode : InText)
	{
		const stbtt_packedchar& CurrInfo = GetPackedchar(static_cast<int32_t>(Unicode));

		int32_t CurrWidth = (CurrInfo.x1 - CurrInfo.x0) + static_cast<int32_t>(CurrInfo.xadvance);
		int32_t CurrHeight = CurrInfo.y1 - CurrInfo.y0;

		TextWidth += CurrWidth;

		if (CurrHeight > TextHeight)
		{
			TextHeight = CurrHeight;
		}
	}

	OutWidth = TextWidth;
	OutHeight = TextHeight;
}

bool Font::LoadTrueTypeFontFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer)
{
	OutBuffer.resize(1 << 25);

	FILE* FontFile = nullptr;
	fopen_s(&FontFile, InPath.c_str(), "rb");

	if (!FontFile) return false;

	fread(&OutBuffer[0], 1, 1 << 25, FontFile);
	fclose(FontFile);
	
	return true;
}

std::shared_ptr<uint8_t[]> Font::GenerateTextureAtlasBitmap(const std::vector<uint8_t>& InBuffer, int32_t InBeginCodePoint, int32_t InEndCodePoint, float InFontSize, std::vector<stbtt_packedchar>& OutPackedchars, int32_t& OutSize)
{
	OutPackedchars.resize(InEndCodePoint - InBeginCodePoint + 1);

	int32_t Success = 0;
	stbtt_pack_context PackContext;
	std::shared_ptr<uint8_t[]> Bitmap = nullptr;

	for (int32_t Size = 16; Size < 8192; Size *= 2)
	{
		Bitmap = std::make_unique<uint8_t[]>(Size * Size);
		Success = stbtt_PackBegin(&PackContext, Bitmap.get(), Size, Size, 0, 1, nullptr);
		stbtt_PackSetOversampling(&PackContext, 1, 1);

		Success = stbtt_PackFontRange(
			&PackContext,
			reinterpret_cast<const unsigned char*>(&InBuffer[0]),
			0,
			InFontSize,
			InBeginCodePoint,
			static_cast<int>(OutPackedchars.size()),
			&OutPackedchars[0]
		);

		if (Success)
		{
			stbtt_PackEnd(&PackContext);
			OutSize = Size;
			break;
		}
		else
		{
			stbtt_PackEnd(&PackContext);
			Bitmap.reset();
		}
	}

	return Bitmap;
}

SDL_Texture* Font::CreateTextureAtlasFromBitmap(SDL_Renderer* InRenderer, const std::shared_ptr<uint8_t[]>& InBitmap, const int32_t InSize)
{
	auto Pixels = std::make_unique<uint32_t[]>(InSize * InSize);

	SDL_Texture* TextureAtlas = SDL_CreateTexture(InRenderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, InSize, InSize);
	CHECK((TextureAtlas != nullptr), "failed to create texture altas");

	CHECK((SDL_SetTextureBlendMode(TextureAtlas, SDL_BLENDMODE_BLEND) == 0), "failed to set blend mode in texture atlas");

	SDL_PixelFormat* Format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA32);
	CHECK((Format != nullptr), "failed to alloc format");

	for (int32_t index = 0; index < InSize * InSize; ++index)
	{
		Pixels[index] = SDL_MapRGBA(Format, 0xFF, 0xFF, 0xFF, InBitmap[index]);
	}

	CHECK((SDL_UpdateTexture(TextureAtlas, nullptr, Pixels.get(), InSize * sizeof(uint32_t)) == 0), "failed to update texture atlas");

	SDL_FreeFormat(Format);
	Format = nullptr;

	return TextureAtlas;
}