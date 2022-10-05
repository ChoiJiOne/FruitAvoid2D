#pragma once

#include "Macro.h"

#include <vector>
#include <string>

struct SDL_Renderer;
struct SDL_Texture;
struct stbtt_packedchar;


/**
 * 폰트에 대응하는 문자들의 텍스처 아틀라스입니다.
 */
class CharacterTextureAtlas
{
public:
	/**
	 * 문자 텍스처 아틀라스 클래스의 생성자입니다.
	 * 
	 * @param InBuffer - 트루 타입 폰트 리소스 버퍼입니다.
	 * @param InBeginCodePoint - 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * @param InEndCodePoint - 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * 
	 * @throws 텍스처 아틀라스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	CharacterTextureAtlas(const std::vector<uint8_t>& InBuffer, int32_t InBeginCodePoint, int32_t InEndCodePoint);


	/**
	 * 문자 텍스처 아틀라스 클래스 가상 소멸자입니다.
	 */
	virtual ~CharacterTextureAtlas();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(CharacterTextureAtlas);


private:
	/**
	 * 문자 텍스처 아틀라스의 코드 포인트 시작점입니다.
	 * 이때, 텍스처 아틀라스는 시작점을 포함합니다.
	 */
	int32_t BeginCodePoint_ = 0;


	/**
	 * 문자 텍스처 아틀라스의 코드 포인트 끝점입니다.
	 * 이때, 텍스처 아틀라스는 끝점을 포함합니다.
	 */
	int32_t EndCodePoint_ = 0;


	/**
	 * 텍스처 아틀라스 상의 코드 포인트에 대응하는 문자 위치 및 크기 정보입니다. 
	 */
	std::vector<stbtt_packedchar> Packedchars_;


	/**
	 * 텍스처 아틀라스입니다.
	 */
	SDL_Texture* TextureAtlas_ = nullptr;
};


/**
 * 폰트 리소스를 관리하는 클래스입니다.
 * 이 폰트 클래스는 텍스처 아틀라스를 기반으로 폰트 데이터를 관리합니다.
 */
class Font
{
public:
	/**
	 * 폰트 클래스의 생성자입니다.
	 * 
	 * @param InRenderer - 텍스처 아틀라스를 생성할 때 사용할 SDL 렌더러입니다.
	 * @param InPath - 로딩할 폰트 리소스의 경로입니다.
	 * @param InSize - 폰트의 크기입니다.
	 * 
	 * @throws
	 * - 폰트 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * - 텍스처 아틀라스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Font(SDL_Renderer* InRenderer, const std::string& InPath, float InSize);


	/**
	 * 폰트 클래스의 가상 소멸자입니다.
	 */
	virtual ~Font();


	/**
	 * 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


private:
	/**
	 * 트루 타입 폰트를 로딩 합니다.
	 * 
	 * @param InPath - 로딩할 트루 타입 폰트 리소스의 경로입니다.
	 * @param OutBuffer - 트루 타입 폰트의 리소스 버퍼입니다.
	 * 
	 * @return 트루 타입 폰트 로딩에 성공하면 true, 그렇지 않으면 false를 반환합니다.
	 */
	static bool LoadTrueTypeFontFromFile(const std::string& InPath, std::vector<uint8_t>& OutBuffer);


private:

};