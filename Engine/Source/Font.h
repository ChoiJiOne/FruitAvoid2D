#pragma once

#include "Macro.h"
#include "Color.h"

class Graphics2D;
struct SDL_Surface;
struct SDL_Texture;
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


	/**
	 * 문자열의 표면을 생성합니다.
	 * 
	 * @param InGraphics - 표면을 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InText - 표면을 생성할 문자열입니다.
	 * @param InColor - 문자열의 색상입니다.
	 */
	SDL_Surface* CreateTextSurface(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor);


	/**
	 * 문자열의 표면을 생성합니다.
	 * 
	 * @param InGraphics - 텍스처를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InText - 표면을 생성할 문자열입니다.
	 * @param InColor - 문자열의 색상입니다.
	 */
	SDL_Surface* CreateTextSurface(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor);


	/**
	 * 문자열의 이미지 리소스를 생성합니다.
	 * 
	 * @param InGraphics - 텍스처를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InText - 이미지 리소스를 생성할 문자열입니다.
	 * @param InColor - 문자열의 색상입니다.
	 */
	SDL_Texture* CreateTextTexture(Graphics2D& InGraphics, const std::string& InText, const LinearColor& InColor);


	/**
	 * 문자열의 이미지 리소스를 생성합니다.
	 *
	 * @param InGraphics - 텍스처를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InText - 이미지 리소스를 생성할 문자열입니다.
	 * @param InColor - 문자열의 색상입니다.
	 */
	SDL_Texture* CreateTextTexture(Graphics2D& InGraphics, const std::wstring& InText, const LinearColor& InColor);


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