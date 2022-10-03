#pragma once

#include "Macro.h"

#include <vector>
#include <string>

struct SDL_Renderer;
struct SDL_Texture;


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

};