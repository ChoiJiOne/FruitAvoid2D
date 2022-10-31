#pragma once

#include "Macro.h"

class Graphics2D;
struct SDL_Texture;


/**
 * 텍스처 클래스입니다.
 */
class Texture
{
public:
	/**
	 * 텍스처 클래스의 생성자입니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처 리소스의 경로입니다.
	 * 
	 * @throws 
	 * - 텍스처 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * - 텍스처 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Texture(Graphics2D& InGraphics, const std::string& InPath);


	/**
	 * 텍스처 클래스의 가상 소멸자입니다.
	 */
	virtual ~Texture();


	/**
	 * 텍스처 클래스의 복사 생성자와 대입 연산자를 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Texture);


	/**
	 * 텍스처 리소스의 포인터를 얻습니다.
	 * 
	 * @return 텍스처 리소스의 포인터를 반환합니다.
	 */
	SDL_Texture* GetTexture() { return Texture_; }


private:
	/**
	 * 파일로 부터 텍스처 리소스를 로딩합니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처 리소스의 경로입니다.
	 * 
	 * @return 텍스처 파일 로딩에 성공하면 텍스처 리소스의 포인터, 실패하면 nullptr를 반환합니다.
	 */
	static SDL_Texture* LoadTextureFromFile(Graphics2D& InGraphics, const std::string& InPath);


private:
	/**
	 * 텍스처 리소스의 포인터입니다.
	 */
	SDL_Texture* Texture_ = nullptr;
};