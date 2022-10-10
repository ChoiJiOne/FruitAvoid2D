#pragma once

#include "Macro.h"

#include <memory>
#include <unordered_map>

struct SDL_Window;
class Texture;
class Font;


/**
 * ���ҽ� ���� Ŭ�����Դϴ�.
 */
class ResourceSystem
{
public:
	/**
	 * ���ҽ� ���� Ŭ������ �������Դϴ�.
	 * 
	 * @param InWindow - ���ҽ� ������ ������ SDL ������ �������Դϴ�.
	 */
	explicit ResourceSystem(SDL_Window* InWindow);


	/**
	 * ���ҽ� ���� Ŭ������ ���� �Ҹ����Դϴ�. 
	 */
	virtual ~ResourceSystem();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� �����մϴ�.
	 */
	DISALLOW_COPY_AND_ASSIGN(ResourceSystem);


	/**
	 * �ؽ�ó�� ������ �ε��մϴ�.
	 * �̶�, �� ���ҽ��� ���ҽ� �ý��� Ŭ������ �����մϴ�.
	 *
	 * @param InKey - �ؽ�ó ������ �ؽ� Ű ���Դϴ�.
	 * @param InPath - �ؽ�ó ������ ����Դϴ�.
	 *
	 * @throws Ű ���� �浹�ϰų� �ؽ�ó ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return ������ �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture& LoadTextureFromFile(const std::size_t& InKey, const std::string& InPath);


	/**
	 * ���ҽ� �ý����� �����ϴ� �ؽ�ó�� ����ϴ�.
	 *
	 * @param InKey - �ؽ�ó�� �ؽ� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� �ؽ�ó�� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	Texture& GetTexture(const std::size_t& InKey);


	/**
	 * Ʈ�� Ÿ�� ��Ʈ�� �ε��մϴ�.
	 * �̶�, �� ���ҽ��� ���ҽ� ������ Ŭ������ �����մϴ�.
	 *
	 * @param InKey - Ʈ�� Ÿ�� ��Ʈ ������ �ؽ� Ű ���Դϴ�.
	 * @param InPath - Ʈ�� Ÿ�� ��Ʈ ������ ����Դϴ�.
	 * @param InBeginCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �������Դϴ�.
	 * @param InEndCodePoint - ���� �ؽ�ó ��Ʋ���� �ڵ� ����Ʈ �����Դϴ�.
	 * @param Ʈ�� Ÿ�� ��Ʈ�� ũ���Դϴ�.
	 *
	 * @throws Ű ���� �浹�ϰų� Ʈ�� Ÿ�� ��Ʈ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return ������ �����ϴ� Ʈ�� Ÿ�� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	Font& LoadFontFromFile(
		const std::size_t& InKey, 
		const std::string& InPath, 
		int32_t InBeginCodePoint,
		int32_t InEndCodePoint, 
		const float InSize
	);


	/**
	 * ������ �����ϴ� Ʈ�� Ÿ�� ��Ʈ�� ����ϴ�.
	 *
	 * @param InKey - Ʈ�� Ÿ�� ��Ʈ�� �ؽ� Ű ���Դϴ�.
	 *
	 * @throws Ű ���� �����ϴ� Ʈ�� Ÿ�� ��Ʈ�� �������� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return Ű ���� �����ϴ� Ʈ�� Ÿ�� ��Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	Font& GetFont(const std::size_t& InKey);


private:
	/**
	 * ���ҽ� ������ ������ SDL ������ �������Դϴ�.
	 */
	SDL_Window* Window_;

	/**
	 * ���ҽ� �ý����� �����ϴ� �ؽ�ó�Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * �Է� ó�� Ŭ�����Դϴ�.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;
};