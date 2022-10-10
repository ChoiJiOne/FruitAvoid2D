#pragma once

#include "Macro.h"

#include <memory>
#include <unordered_map>

struct SDL_Window;
class Texture;
class Font;


/**
 * 리소스 관리 클래스입니다.
 */
class ResourceSystem
{
public:
	/**
	 * 리소스 관리 클래스의 생성자입니다.
	 * 
	 * @param InWindow - 리소스 생성에 참조할 SDL 윈도우 포인터입니다.
	 */
	explicit ResourceSystem(SDL_Window* InWindow);


	/**
	 * 리소스 관리 클래스의 가상 소멸자입니다. 
	 */
	virtual ~ResourceSystem();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(ResourceSystem);


	/**
	 * 텍스처를 파일을 로딩합니다.
	 * 이때, 이 리소스는 리소스 시스템 클래스가 관리합니다.
	 *
	 * @param InKey - 텍스처 파일의 해쉬 키 값입니다.
	 * @param InPath - 텍스처 파일의 경로입니다.
	 *
	 * @throws 키 값이 충돌하거나 텍스처 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 엔진이 관리하는 텍스처의 참조자를 반환합니다.
	 */
	Texture& LoadTextureFromFile(const std::size_t& InKey, const std::string& InPath);


	/**
	 * 리소스 시스템이 관리하는 텍스처를 얻습니다.
	 *
	 * @param InKey - 텍스처의 해쉬 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 텍스처가 존재하지 않으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 텍스처의 참조자를 반환합니다.
	 */
	Texture& GetTexture(const std::size_t& InKey);


	/**
	 * 트루 타입 폰트를 로딩합니다.
	 * 이때, 이 리소스는 리소스 스시템 클래스가 관리합니다.
	 *
	 * @param InKey - 트루 타입 폰트 파일의 해쉬 키 값입니다.
	 * @param InPath - 트루 타입 폰트 파일의 경로입니다.
	 * @param InBeginCodePoint - 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * @param InEndCodePoint - 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * @param 트루 타입 폰트의 크기입니다.
	 *
	 * @throws 키 값이 충돌하거나 트루 타입 폰트 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 엔진이 관리하는 트루 타입 폰트의 참조자를 반환합니다.
	 */
	Font& LoadFontFromFile(
		const std::size_t& InKey, 
		const std::string& InPath, 
		int32_t InBeginCodePoint,
		int32_t InEndCodePoint, 
		const float InSize
	);


	/**
	 * 엔진이 관리하는 트루 타입 폰트를 얻습니다.
	 *
	 * @param InKey - 트루 타입 폰트의 해쉬 키 값입니다.
	 *
	 * @throws 키 값에 대응하는 트루 타입 폰트가 존재하지 않으면 C++ 표준 예외를 던집니다.
	 *
	 * @return 키 값에 대응하는 트루 타입 폰트의 참조자를 반환합니다.
	 */
	Font& GetFont(const std::size_t& InKey);


private:
	/**
	 * 리소스 생성에 참조할 SDL 윈도우 포인터입니다.
	 */
	SDL_Window* Window_;

	/**
	 * 리소스 시스템이 관리하는 텍스처입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Texture>> Textures_;


	/**
	 * 입력 처리 클래스입니다.
	 */
	std::unordered_map<std::size_t, std::unique_ptr<Font>> Fonts_;
};