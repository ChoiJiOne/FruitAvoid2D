#pragma once

#include "Macro.h"

#include <vector>
#include <string>

struct SDL_Renderer;
struct SDL_Texture;
struct stbtt_packedchar;


/**
 * ��Ʈ�� �����ϴ� ���ڵ��� �ؽ�ó ��Ʋ���Դϴ�.
 */
class CharacterTextureAtlas
{
public:
	/**
	 * ���� �ؽ�ó ��Ʋ�� Ŭ������ �������Դϴ�.
	 * 
	 * @param InBuffer - Ʈ�� Ÿ�� ��Ʈ ���ҽ� �����Դϴ�.
	 * @param InBeginCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param InEndCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * 
	 * @throws �ؽ�ó ��Ʋ�� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	CharacterTextureAtlas(const std::vector<uint8_t>& InBuffer, int32_t InBeginCodePoint, int32_t InEndCodePoint);


	/**
	 * ���� �ؽ�ó ��Ʋ�� Ŭ���� ���� �Ҹ����Դϴ�.
	 */
	virtual ~CharacterTextureAtlas();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(CharacterTextureAtlas);


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


/**
 * ��Ʈ ���ҽ��� �����ϴ� Ŭ�����Դϴ�.
 * �� ��Ʈ Ŭ������ �ؽ�ó ��Ʋ�󽺸� ������� ��Ʈ �����͸� �����մϴ�.
 */
class Font
{
public:
	/**
	 * ��Ʈ Ŭ������ �������Դϴ�.
	 * 
	 * @param InRenderer - �ؽ�ó ��Ʋ�󽺸� ������ �� ����� SDL �������Դϴ�.
	 * @param InPath - �ε��� ��Ʈ ���ҽ��� ����Դϴ�.
	 * @param InSize - ��Ʈ�� ũ���Դϴ�.
	 * 
	 * @throws
	 * - ��Ʈ ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó ��Ʋ�� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Font(SDL_Renderer* InRenderer, const std::string& InPath, float InSize);


	/**
	 * ��Ʈ Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Font();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


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


private:

};