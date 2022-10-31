#pragma once

#include "Macro.h"

typedef struct _TTF_Font TTF_Font;

/**
 * 트루 타입 폰트 클래스입니다.
 */
class Font
{
public:
	/**
	 * 트루 타입 폰트 클래스의 생성자입니다.
	 * 
	 * @param InPath - 트루 타입 폰트 파일의 경로입니다.
	 * @param InSize - 폰트의 크기입니다.
	 * 
	 * @throws
	 * - 트루 타입 폰트 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * - 트루 타입 폰트 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Font(const std::string& InPath, const int32_t& InSize);


	/**
	 * 트루 타입 폰트 클래스의 가상 소멸자입니다.
	 */
	virtual ~Font();


	/**
	 * 트루 타입 폰트 클래스의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Font);


	/**
	 * 트루 타입 폰트 리소스의 포인터를 얻습니다.
	 * 
	 * @return 트루 타입 폰트 리소스의 포인터를 반환합니다.
	 */
	TTF_Font* GetFont() { return Font_; }


	/**
	 * 트루 타입 폰트의 크기를 얻습니다.
	 * 
	 * @return 트루 타입 폰트의 크기를 반환합니다.
	 */
	int32_t GetSize() { return Size_; }


private:
	/**
	 * 트루 타입 폰트 리스소의 포인터입니다.
	 */
	TTF_Font* Font_ = nullptr;


	/**
	 * 폰트의 크기입니다.
	 */
	int32_t Size_ = 0;
};