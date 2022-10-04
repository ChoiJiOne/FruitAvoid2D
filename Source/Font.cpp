#include "Font.h"

// @third party code - BEGIN SDL2, stb
#include <SDL2/SDL.h>
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>
// @third party code - END

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
