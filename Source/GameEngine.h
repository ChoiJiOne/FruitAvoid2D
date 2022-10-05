#pragma once

#if defined(_DEBUG) || defined(DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <list>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <filesystem>
#include <unordered_map>

#include "Color.h"
#include "Font.h"
#include "Random.h"
#include "Text.h"
#include "Texture.h"
#include "Timer.h"
#include "Vector.h"
#include "WindowSystem.h"
#include "InputSystem.h"
#include "RenderSystem.h"
#include "ResourceSystem.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <json/json.hpp>
#include <spdlog/spdlog.h>
#include <stb/stb_image.h>
#include <stb/stb_truetype.h>
// @third party code - END


/**
 * 게임 엔진 클래스입니다.
 * 전체 게임 리소스 관리 및 초기화/해제를 담당합니다.
 * 이 클래스는 정적 클래스로 헤더 선언만 추가하면 바로 사용할 수 있습니다.
 */
class GameEngine
{
public:
	/**
	 * 게임 엔진의 초기화 및 게임 내의 기본 리소스를 생성 합니다.
	 *
	 * @throws 초기화 또는 리소스 생성에 실패하면 C++ 표준 예외를 던집니다.
	 */
	static void Init();


	/**
	 * 게임 엔진의 해제 및 게임 내의 리소스를 제거합니다.
	 */
	static void Quit();


	/**
	 * 게임 엔진의 루트 디렉토리를 얻습니다.
	 *
	 * @return 엔진이 관리하는 루트 디렉토리를 반환합니다.
	 */
	static std::string GetRootDirectory() { return RootDirectory_; }


	/**
	 * 게임 엔진이 관리하는 윈도우를 생성합니다.
	 *
	 * @param InTitle - 윈도우의 타이틀입니다.
	 * @param InPositionX - 윈도우 왼쪽 상단의 X좌표입니다.
	 * @param InPositionY - 윈도우 왼쪽 상단의 Y좌표입니다.
	 * @param InWidth - 윈도우의 가로 크기입니다.
	 * @param InHeight - 윈도우의 세로 크기입니다.
	 * @param InFlags - 윈도우 옵션입니다.
	 *
	 * @throws 윈도우 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 엔진이 관리하는 윈도우의 참조자를 반환합니다.
	 */
	static WindowSystem& CreateWindowSystem(
		const std::string& InTitle,
		int32_t InPositionX,
		int32_t InPositionY,
		int32_t InWidth,
		int32_t InHeight,
		uint32_t InFlags
	);


	/**
	 * 게임 엔진이 관리하는 윈도우를 얻습니다.
	 *
	 * @return 게임 엔진이 관리하는 윈도우의 참조자를 반환합니다.
	 */
	static WindowSystem& GetWindowSystem() { return *WindowSystem_.get(); }


	/**
	 * 게임 엔진이 관리하는 렌더 시스템을 생성합니다.
	 *
	 * @param bIsAccelerated - 하드웨어 가속여부입니다.
	 * @param bIsActiveVsync - 수직 동기화 활성화 여부입니다.
	 *
	 * @throws 렌더 시스템 생성에 실패하면 C++ 표준 예외를 던집니다.
	 *
	 * @return 게임 엔진이 관리하는 렌더 시스템의 참조자를 반환합니다.
	 */
	static RenderSystem& CreateRenderSystem(bool bIsAccelerated = true, bool bIsActiveVsync = true);


	/**
	 * 게임 엔진이 관리하는 렌더 시스템을 얻습니다.
	 *
	 * @return 게임 엔진이 관리하는 렌더 시스템의 참조자를 반환합니다.
	 */
	static RenderSystem& GetRenderSystem() { return *RenderSystem_.get(); }


	/**
	 * 게임 엔진이 관리하는 입력 처리 시스템을 생성합니다.
	 *
	 * @return 게임 엔진이 관리하는 입력 처리 시스템의 참조자를 반환합니다.
	 */
	static InputSystem& CreateInputSystem();


	/**
	 * 게임 엔진이 관리하는 입력 처리 시스템을 얻습니다.
	 *
	 * @return 게임 엔진이 관리하는 입력 처리 시스템의 참조자를 반환합니다.
	 */
	static InputSystem& GetInputSystem() { return *InputSystem_.get(); }


	/**
	 * 게임 엔진이 관리하는 리소스 관리 시스템을 생성합니다.
	 *
	 * @return 게임 엔진이 관리하는 리소스 관리 시스템의 참조자를 반환합니다.
	 */
	static ResourceSystem& CreateResourceSystem();


	/**
	 * 게임 엔진이 관리하는 리소스 관리 시스템을 얻습니다.
	 *
	 * @return 게임 엔진이 관리하는 리소스 관리 시스템의 참조자를 반환합니다.
	 */
	static ResourceSystem& GetResourceSystem() { return *ResourceSystem_.get(); }


private:
	/**
	 * 게임의 루트 디렉토리입니다.
	 */
	static std::string RootDirectory_;


	/**
	 * 게임 엔진이 관리하는 윈도우 시스템입니다.
	 */
	static std::unique_ptr<WindowSystem> WindowSystem_;


	/**
	 * 게임 엔진이 관리하는 렌더 시스템입니다.
	 */
	static std::unique_ptr<RenderSystem> RenderSystem_;


	/**
	 * 게임 엔진이 관리하는 입력 시스템입니다.
	 */
	static std::unique_ptr<InputSystem> InputSystem_;


	/**
	 * 게임 엔진이 관리하는 리소스 시스템입니다.
	 */
	static std::unique_ptr<ResourceSystem> ResourceSystem_;
};