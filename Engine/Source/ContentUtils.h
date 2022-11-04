#pragma once

#include <json/json.hpp>
using json = nlohmann::json;

class Texture;
class Font;


/**
 * ������(ex. �ؽ�ó, ��Ʈ, json ���� ���)�� �߰�, ����, �˻� ���� ������ �����ϴ� Ŭ�����Դϴ�.
 */
class ContentUtils
{
public:
	/**
	 * �������� �����ϴ� Ŭ������ �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * �������� �����ϴ� Ŭ������ ���ҽ��� �����մϴ�.
	 */
	static void Quit();


private:
	/**
	 * ContentUtils�� �����ϴ� �ؽ�ó�Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentUtils�� �����ϴ� ��Ʈ�Դϴ�.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentUtils�� �����ϴ� Json �����Դϴ�.
	 */
	static std::unordered_map<std::size_t, json> Jsons_;
};