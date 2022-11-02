#pragma once

#include "Macro.h"

class Graphics;
struct SDL_Surface;
struct SDL_Texture;


/**
 * �ؽ�ó Ŭ�����Դϴ�.
 */
class Texture
{
public:
	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 * �̶�, �ؽ�ó ���ҽ��� �ؽ�ó ������ �ε��ؼ� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó ���ҽ��� ����Դϴ�.
	 * 
	 * @throws 
	 * - �ؽ�ó ���� �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(Graphics& InGraphics, const std::string& InPath);


	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 * �̶�, �ؽ�ó ���ҽ��� SDL_Surface�� ������� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InSurface - �ؽ�ó ǥ���Դϴ�.
	 * 
	 * @throws 
	 * - �Ķ���Ͱ� ��ȿ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(Graphics& InGraphics, SDL_Surface* InSurface);


	/**
	 * �ؽ�ó Ŭ������ �������Դϴ�.
	 * �̶�, �Ķ���ͷ� �Է� ���� SDL_Texture�� �����մϴ�.
	 * 
	 * @param InTexture - �ؽ�ó ���ҽ��� �������Դϴ�.
	 * 
	 * @throws �Ķ���Ͱ� ��ȿ���� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	explicit Texture(SDL_Texture* InTexture);


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


	/**
	 * �ؽ�ó ���ҽ��� ���� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @param OutWidth - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 * @param OutHeight - �ؽ�ó ���ҽ��� ���� ũ���Դϴ�.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * ���Ϸ� ���� �ؽ�ó SDL �ؽ�ó ���ҽ��� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó ���ҽ��� ����Դϴ�.
	 * 
	 * @return �ؽ�ó ���� �ε��� �����ϸ� �ؽ�ó ���ҽ��� ������, �����ϸ� nullptr�� ��ȯ�մϴ�.
	 */
	static SDL_Texture* CreateTextureFromFile(Graphics& InGraphics, const std::string& InPath);


	/**
	 * SDL �ؽ�ó ǥ������ ���� SDL �ؽ�ó ���ҽ��� �����մϴ�.
	 * 
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InSurface - �ؽ�ó ǥ���Դϴ�.
	 *
	 * @throws �ؽ�ó ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	static SDL_Texture* CreateTextureFromSurface(Graphics& InGraphics, SDL_Surface* InSurface);


private:
	/**
	 * �ؽ�ó ���ҽ��� �������Դϴ�.
	 */
	SDL_Texture* Texture_ = nullptr;
};