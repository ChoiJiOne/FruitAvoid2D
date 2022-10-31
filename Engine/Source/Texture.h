#pragma once

#include "Macro.h"

class Graphics2D;
struct SDL_Texture;


/**
 * �ؽ�ó Ŭ�����Դϴ�.
 */
class Texture
{
public:
	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó ���ҽ��� ����Դϴ�.
	 * 
	 * @throws 
	 * - �ؽ�ó ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(Graphics2D& InGraphics, const std::string& InPath);


	/**
	 * �ؽ�ó Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Texture();


	/**
	 * �ؽ�ó Ŭ������ ���� �����ڿ� ���� �����ڸ� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(Texture);


	/**
	 * �ؽ�ó ���ҽ��� �����͸� ����ϴ�.
	 * 
	 * @return �ؽ�ó ���ҽ��� �����͸� ��ȯ�մϴ�.
	 */
	SDL_Texture* GetTexture() { return Texture_; }


private:
	/**
	 * ���Ϸ� ���� �ؽ�ó ���ҽ��� �ε��մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó ���ҽ��� ����Դϴ�.
	 * 
	 * @return �ؽ�ó ���� �ε��� �����ϸ� �ؽ�ó ���ҽ��� ������, �����ϸ� nullptr�� ��ȯ�մϴ�.
	 */
	static SDL_Texture* LoadTextureFromFile(Graphics2D& InGraphics, const std::string& InPath);


private:
	/**
	 * �ؽ�ó ���ҽ��� �������Դϴ�.
	 */
	SDL_Texture* Texture_ = nullptr;
};