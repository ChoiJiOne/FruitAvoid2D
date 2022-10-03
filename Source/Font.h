#pragma once

#include "Macro.h"

#include <vector>
#include <string>

struct SDL_Renderer;
struct SDL_Texture;


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

};