#pragma once

#include <json/json.hpp>
using json = nlohmann::json;

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


private:
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