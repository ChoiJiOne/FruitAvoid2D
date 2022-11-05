#pragma once

#include <json/json.hpp>
using json = nlohmann::json;

class Graphics;
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


	/**
	 * �ؽ�ó �������� �߰��մϴ�.
	 * 
	 * @param InKey - �ؽ�ó ���ҽ��� �ؽ� Ű���Դϴ�.
	 * @param InGraphics - �ؽ�ó ���ҽ��� ������ �� ����� �׷��Ƚ� �ν��Ͻ��Դϴ�.
	 * @param InPath - �ؽ�ó ���ҽ��� ��� �Դϴ�. �̶�, Content ������ �������� ���ڸ� �����ؾ� �մϴ�.
	 * 
	 * @throws 
	 * - �߰��� �ؽ�ó �������� ��ο� ������ C++ ǥ�� ���ܸ� �����ϴ�.
	 * - �ؽ�ó �ε��� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 * 
	 * @return �߰��� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Texture& AddTexture(const std::size_t& InKey, Graphics& InGraphics, const std::string& InPath);


	/**
	 * ���� ���� �ؽ�ó�� �����մϴ�.
	 * 
	 * @param InKey - ������ �ؽ�ó�� �ؽ� Ű ���Դϴ�.
	 */
	static void RemoveTexture(const std::size_t& InKey);


	/**
	 * Ű ���� �����ϴ� �ؽ�ó�� �ִ��� Ȯ���մϴ�.
	 * 
	 * @param InKey - �ؽ�ó�� �ִ��� Ȯ���� Ű ���Դϴ�.
	 * 
	 * @return Ű ���� ���� ���� �ؽ�ó�� Ű �� �̶�� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveTexture(const std::size_t& InKey);


	/**
	 * ���� ���� �ؽ�ó�� ����ϴ�.
	 * 
	 * @param InKey - ����� �Ǵ� �ؽ�ó�� Ű ���Դϴ�.
	 * 
	 * @return Ű ���� �����ϴ� �ؽ�ó�� �����ڸ� ��ȯ�մϴ�.
	 */
	static Texture& GetTexture(const std::size_t& InKey);


private:
	/**
	 * ������ ���ҽ��� ���� ����Դϴ�.
	 */
	static std::string ContentPath_;


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