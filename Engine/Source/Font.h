#pragma once

#include "Macro.h"

#include <vector>
#include <string>

// @third party code - BEGIN stb
#include <stb/stb_rect_pack.h>
#include <stb/stb_truetype.h>
// @third party code - END

struct SDL_Renderer;
struct SDL_Texture;


/**
 * ��Ʈ�� �����ϴ� ���ڵ��� �ؽ�ó ��Ʋ���Դϴ�.
 */
class Font
{
public:
	/**
	 * ���� �ؽ�ó ��Ʋ�� Ŭ������ �������Դϴ�.
	 * 
	 * @param InRenderer - �ؽ�ó ��Ʋ�󽺸� ������ �� ����� SDL �������Դϴ�.
	 * @param InPath - �ε��� ��Ʈ ���ҽ��� ����Դϴ�.
	 * @param InBeginCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param InEndCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param InFontSize - ��Ʈ�� ũ���Դϴ�.
	 * 
	 * @throws �ؽ�ó ��Ʋ�� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	Font(
		SDL_Renderer* InRenderer, 
		const std::string& InPath, 
		int32_t InBeginCodePoint, 
		int32_t InEndCodePoint, 
		float InFontSize
	);


	/**
	 * ���� �ؽ�ó ��Ʋ�� Ŭ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~Font();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


	/**
	 * �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� ������ ����ϴ�.
	 * 
	 * @param InCodePoint - ��ġ �� ������ �˰� ���� �ڵ� ����Ʈ ���Դϴ�.
	 * 
	 * @throws �ڵ� ����Ʈ ���� ���� ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �ڵ� ����Ʈ�� �����ϴ� ������ ��ġ �� ũ�� ������ ��ȯ�մϴ�. 
	 */
	const stbtt_packedchar& GetPackedchar(int32_t InCodePoint);


	/**
	 * ���� �ؽ�ó ��Ʋ�󽺸� ����ϴ�.
	 * 
	 * @return �ؽ�ó ��Ʋ�󽺸� ��ȯ�մϴ�.
	 */
	SDL_Texture* GetTextureAtlas() { return TextureAtlas_; }


	/**
	 * �ڵ� ����Ʈ�� ���� ���� ���ԵǴ��� Ȯ���մϴ�.
	 * 
	 * @param InCodePoint - ���� �˻縦 ������ �ڵ� ����Ʈ ���Դϴ�.
	 * 
	 * @return ���� ���� �ִٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool HasCodePointInRange(int32_t InCodePoint);


	/**
	 * �ؽ�Ʈ�� ũ�⸦ �����մϴ�.
	 * ���� ������ �ȼ� �����Դϴ�.
	 * 
	 * @param InText - ������ �ؽ�Ʈ�Դϴ�.
	 * @param OutWidth - ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 * @param OutHeight - ������ �ؽ�Ʈ�� ���� ũ���Դϴ�.
	 */
	void MeasureText(const std::wstring& InText, int32_t& OutWidth, int32_t& OutHeight);


private:
	/**
	 * Ʈ�� Ÿ�� ��Ʈ�� �ε� �մϴ�.
	 * 
	 * @param InPath - �ε��� Ʈ�� Ÿ�� ��Ʈ ���ҽ��� ����Դϴ�.
	 * @param OutBuffer - Ʈ�� Ÿ�� ��Ʈ�� ���ҽ� �����Դϴ�.
	 * 
	 * @return Ʈ�� Ÿ�� ��Ʈ �ε��� �����ϸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	static bool LoadTrueTypeFontFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer);


	/**
	 * �ؽ�ó ��Ʋ�� ��Ʈ���� �����մϴ�.
	 * �̶�, �ؽ�ó ��Ʋ���� ���� ���� ũ��� �����ϴ�.
	 * 
	 * @param InBuffer - Ʈ�� Ÿ�� ��Ʈ ���ҽ� �����Դϴ�.
	 * @param InBeginCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param InEndCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param InFontSize - ��Ʈ�� ũ���Դϴ�.
	 * @param OutPackedchars - �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�. 
	 * @param OutSize - �ؽ�ó ��Ʋ�� ũ���Դϴ�.
	 * 
	 * @return ������ �ؽ�ó ��Ʋ�� ��Ʈ���� ��ȯ�մϴ�.
	 */
	static std::shared_ptr<uint8_t[]> GenerateTextureAtlasBitmap(
		const std::vector<uint8_t>& InBuffer, 
		int32_t InBeginCodePoint, 
		int32_t InEndCodePoint, 
		float InFontSize,
		std::vector<stbtt_packedchar>& OutPackedchars,
		int32_t& OutSize
	);


	/**
	 * �ؽ�ó ��Ʋ�� ��Ʈ������ ���� �ؽ�ó ���ҽ��� �����մϴ�.
	 * 
	 * @param InRenderer - �ؽ�ó ���ҽ� ������ ����� SDL �������Դϴ�.
	 * @param InBitmap - �ؽ�ó ��Ʋ�� ��Ʈ���Դϴ�.
	 * @param InSize - �ؽ�ó ��Ʋ�� ��Ʈ���� ���� ���� ũ���Դϴ�
	 * 
	 * @throws �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �ؽ�ó ��Ʋ�󽺸� ��ȯ�մϴ�.
	 */
	static SDL_Texture* CreateTextureAtlasFromBitmap(
		SDL_Renderer* InRenderer,
		const std::shared_ptr<uint8_t[]>& InBitmap,
		const int32_t InSize
	);


private:
	/**
	 * ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * �̶�, �ؽ�ó ��Ʋ�󽺴� �������� �����մϴ�.
	 */
	int32_t BeginCodePoint_ = 0;


	/**
	 * ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * �̶�, �ؽ�ó ��Ʋ�󽺴� ������ �����մϴ�.
	 */
	int32_t EndCodePoint_ = 0;


	/**
	 * �ؽ�ó ��Ʋ�� ���� �ڵ� ����Ʈ�� �����ϴ� ���� ��ġ �� ũ�� �����Դϴ�. 
	 */
	std::vector<stbtt_packedchar> Packedchars_;


	/**
	 * �ؽ�ó ��Ʋ���Դϴ�.
	 */
	SDL_Texture* TextureAtlas_ = nullptr;
};
