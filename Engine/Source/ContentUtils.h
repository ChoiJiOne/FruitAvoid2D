#pragma once

#include <json/json.hpp>
using json = nlohmann::json;

class Graphics;
class Texture;
class Font;


/**
 * 컨텐츠(ex. 텍스처, 폰트, json 파일 등등)를 추가, 삭제, 검색 등의 관리를 수행하는 클래스입니다.
 */
class ContentUtils
{
public:
	/**
	 * 컨텐츠를 관리하는 클래스를 초기화합니다.
	 */
	static void Init();


	/**
	 * 컨텐츠를 관리하는 클래스의 리소스를 정리합니다.
	 */
	static void Quit();


	/**
	 * 텍스처 컨텐츠를 추가합니다.
	 * 
	 * @param InKey - 텍스처 리소스의 해쉬 키값입니다.
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처 리소스의 경로 입니다. 이때, Content 폴더를 기준으로 인자를 전달해야 합니다.
	 * 
	 * @throws 
	 * - 추가할 텍스처 컨텐츠가 경로에 없으면 C++ 표준 예외를 던집니다.
	 * - 텍스처 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * 
	 * @return 추가한 텍스처의 참조자를 반환합니다.
	 */
	static Texture& AddTexture(const std::size_t& InKey, Graphics& InGraphics, const std::string& InPath);


	/**
	 * 관리 중인 텍스처를 삭제합니다.
	 * 
	 * @param InKey - 삭제할 텍스처의 해쉬 키 값입니다.
	 */
	static void RemoveTexture(const std::size_t& InKey);


	/**
	 * 키 값에 대응하는 텍스처가 있는지 확인합니다.
	 * 
	 * @param InKey - 텍스처가 있는지 확인할 키 값입니다.
	 * 
	 * @return 키 값이 관리 중인 텍스처의 키 값 이라면 true, 그렇지 않다면 false를 반환합니다.
	 */
	static bool HaveTexture(const std::size_t& InKey);


	/**
	 * 관리 중인 텍스처를 얻습니다.
	 * 
	 * @param InKey - 대상이 되는 텍스처의 키 값입니다.
	 * 
	 * @return 키 값에 대응하는 텍스처의 참조자를 반환합니다.
	 */
	static Texture& GetTexture(const std::size_t& InKey);


private:
	/**
	 * 컨텐츠 리소스의 폴더 경로입니다.
	 */
	static std::string ContentPath_;


	/**
	 * ContentUtils이 관리하는 텍스처입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * ContentUtils이 관리하는 폰트입니다.
	 */
	static std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;


	/**
	 * ContentUtils이 관리하는 Json 파일입니다.
	 */
	static std::unordered_map<std::size_t, json> Jsons_;
};