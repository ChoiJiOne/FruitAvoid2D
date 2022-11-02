#pragma once

#include "Macro.h"
#include "Color.h"

class Graphics2D;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

/**
 * Ʈ�� Ÿ�� ��Ʈ Ŭ�����Դϴ�.
 */
class Font
{
public:
	/**
	 * Ʈ�� Ÿ�� ��Ʈ Ŭ������ �������Դϴ�.
	 * 
	 * @param InPath - Ʈ�� Ÿ�� ��Ʈ ������ ����Դϴ�.
	 * @param InSize - ��Ʈ�� ũ���Դϴ�.
	 * 
	 * @throws
	 * - Ʈ�� Ÿ�� ��Ʈ ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - Ʈ�� Ÿ�� ��Ʈ ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Font(const std::string& InPath, const int32_t& InSize);


	/**
	 * Ʈ�� Ÿ�� ��Ʈ Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Font();


	/**
	 * Ʈ�� Ÿ�� ��Ʈ Ŭ������ ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


	/**
	 * Ʈ�� Ÿ�� ��Ʈ ���ҽ��� �����͸� ����ϴ�.
	 * 
	 * @return Ʈ�� Ÿ�� ��Ʈ ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	TTF_Font* GetFont() { return Font_; }


	/**
	 * Ʈ�� Ÿ�� ��Ʈ�� ũ�⸦ ����ϴ�.
	 * 
	 * @return Ʈ�� Ÿ�� ��Ʈ�� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetSize() { return Size_; }


	/**
	 * ���ڿ��� ǥ���� �����մϴ�.
	 * 
	 * @param InGraphics - ǥ���� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InText - ǥ���� ������ ���ڿ��Դϴ�.
	 * @param InColor - ���ڿ��� �����Դϴ�.
	 */
	SDL_Surface* CreateTextSurface(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor);


	/**
	 * ���ڿ��� ǥ���� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó�� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InText - ǥ���� ������ ���ڿ��Դϴ�.
	 * @param InColor - ���ڿ��� �����Դϴ�.
	 */
	SDL_Surface* CreateTextSurface(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor);


	/**
	 * ���ڿ��� �̹��� ���ҽ��� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó�� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InText - �̹��� ���ҽ��� ������ ���ڿ��Դϴ�.
	 * @param InColor - ���ڿ��� �����Դϴ�.
	 */
	SDL_Texture* CreateTextTexture(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor);


	/**
	 * ���ڿ��� �̹��� ���ҽ��� �����մϴ�.
	 *
	 * @param InGraphics - �ؽ�ó�� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InText - �̹��� ���ҽ��� ������ ���ڿ��Դϴ�.
	 * @param InColor - ���ڿ��� �����Դϴ�.
	 */
	SDL_Texture* CreateTextTexture(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor);


private:
	/**
	 * Ʈ�� Ÿ�� ��Ʈ �������� �������Դϴ�.
	 */
	TTF_Font* Font_ = nullptr;


	/**
	 * ��Ʈ�� ũ���Դϴ�.
	 */
	int32_t Size_ = 0;
};