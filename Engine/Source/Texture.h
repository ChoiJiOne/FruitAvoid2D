#pragma once

#include "Macro.h"

class Graphics;
struct SDL_Surface;
struct SDL_Texture;


/**
 * 텍스처 클래스입니다.
 */
class Texture
{
public:
	/**
	 * 텍스처 클래스의 생성자입니다.
	 * 이때, 텍스처 리소스는 텍스처 파일을 로딩해서 생성합니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처 리소스의 경로입니다.
	 * 
	 * @throws 
	 * - 텍스처 파일 로딩에 실패하면 C++ 표준 예외를 던집니다.
	 * - 텍스처 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Texture(Graphics& InGraphics, const std::string& InPath);


	/**
	 * 텍스처 클래스의 생성자입니다.
	 * 이때, 텍스처 리소스는 SDL_Surface를 기반으로 생성합니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InSurface - 텍스처 표면입니다.
	 * 
	 * @throws 
	 * - 파라미터가 유효하지 않으면 C++ 표준 예외를 던집니다.
	 * - 텍스처 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	explicit Texture(Graphics& InGraphics, SDL_Surface* InSurface);


	/**
	 * 텍스처 클래스의 생성자입니다.
	 * 이때, 파라미터로 입력 받은 SDL_Texture를 관리합니다.
	 * 
	 * @param InTexture - 텍스처 리소스의 포인터입니다.
	 * 
	 * @throws 파라미터가 유효하지 않으면 C++ 표준 예외를 던집니다.
	 */
	explicit Texture(SDL_Texture* InTexture);


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


	/**
	 * 텍스처 리소스의 가로 세로 크기를 얻습니다.
	 * 
	 * @param OutWidth - 텍스처 리소스의 가로 크기입니다.
	 * @param OutHeight - 텍스처 리소스의 세로 크기입니다.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight);


	/**
	 * 파일로 부터 텍스처 SDL 텍스처 리소스를 생성합니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InPath - 텍스처 리소스의 경로입니다.
	 * 
	 * @return 텍스처 파일 로딩에 성공하면 텍스처 리소스의 포인터, 실패하면 nullptr를 반환합니다.
	 */
	static SDL_Texture* CreateTextureFromFile(Graphics& InGraphics, const std::string& InPath);


	/**
	 * SDL 텍스처 표면으로 부터 SDL 텍스처 리소스를 생성합니다.
	 * 
	 * @param InGraphics - 텍스처 리소스를 생성할 때 사용할 그래픽스 인스턴스입니다.
	 * @param InSurface - 텍스처 표면입니다.
	 *
	 * @throws 텍스처 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	static SDL_Texture* CreateTextureFromSurface(Graphics& InGraphics, SDL_Surface* InSurface);


private:
	/**
	 * 텍스처 리소스의 포인터입니다.
	 */
	SDL_Texture* Texture_ = nullptr;
};