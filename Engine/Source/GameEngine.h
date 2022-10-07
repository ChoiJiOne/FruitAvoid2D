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
 * ���� ���� Ŭ�����Դϴ�.
 * ��ü ���� ���ҽ� ���� �� �ʱ�ȭ/������ ����մϴ�.
 * �� Ŭ������ ���� Ŭ������ ��� ���� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class GameEngine
{
public:
	/**
	 * ���� ������ �ʱ�ȭ �� ���� ���� �⺻ ���ҽ��� ���� �մϴ�.
	 *
	 * @throws �ʱ�ȭ �Ǵ� ���ҽ� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	static void Init();


	/**
	 * ���� ������ ���� �� ���� ���� ���ҽ��� �����մϴ�.
	 */
	static void Quit();


	/**
	 * ���� ������ ��Ʈ ���丮�� ����ϴ�.
	 *
	 * @return ������ �����ϴ� ��Ʈ ���丮�� ��ȯ�մϴ�.
	 */
	static std::string GetRootDirectory() { return RootDirectory_; }


	/**
	 * ���� ������ �����ϴ� �����츦 �����մϴ�.
	 *
	 * @param InTitle - �������� Ÿ��Ʋ�Դϴ�.
	 * @param InPositionX - ������ ���� ����� X��ǥ�Դϴ�.
	 * @param InPositionY - ������ ���� ����� Y��ǥ�Դϴ�.
	 * @param InWidth - �������� ���� ũ���Դϴ�.
	 * @param InHeight - �������� ���� ũ���Դϴ�.
	 * @param InFlags - ������ �ɼ��Դϴ�.
	 *
	 * @throws ������ ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return ������ �����ϴ� �������� �����ڸ� ��ȯ�մϴ�.
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
	 * ���� ������ �����ϴ� �����츦 ����ϴ�.
	 *
	 * @return ���� ������ �����ϴ� �������� �����ڸ� ��ȯ�մϴ�.
	 */
	static WindowSystem& GetWindowSystem() { return *WindowSystem_.get(); }


	/**
	 * ���� ������ �����ϴ� ���� �ý����� �����մϴ�.
	 *
	 * @param bIsAccelerated - �ϵ���� ���ӿ����Դϴ�.
	 * @param bIsActiveVsync - ���� ����ȭ Ȱ��ȭ �����Դϴ�.
	 *
	 * @throws ���� �ý��� ������ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 *
	 * @return ���� ������ �����ϴ� ���� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static RenderSystem& CreateRenderSystem(bool bIsAccelerated = true, bool bIsActiveVsync = true);


	/**
	 * ���� ������ �����ϴ� ���� �ý����� ����ϴ�.
	 *
	 * @return ���� ������ �����ϴ� ���� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static RenderSystem& GetRenderSystem() { return *RenderSystem_.get(); }


	/**
	 * ���� ������ �����ϴ� �Է� ó�� �ý����� �����մϴ�.
	 *
	 * @return ���� ������ �����ϴ� �Է� ó�� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static InputSystem& CreateInputSystem();


	/**
	 * ���� ������ �����ϴ� �Է� ó�� �ý����� ����ϴ�.
	 *
	 * @return ���� ������ �����ϴ� �Է� ó�� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static InputSystem& GetInputSystem() { return *InputSystem_.get(); }


	/**
	 * ���� ������ �����ϴ� ���ҽ� ���� �ý����� �����մϴ�.
	 *
	 * @return ���� ������ �����ϴ� ���ҽ� ���� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static ResourceSystem& CreateResourceSystem();


	/**
	 * ���� ������ �����ϴ� ���ҽ� ���� �ý����� ����ϴ�.
	 *
	 * @return ���� ������ �����ϴ� ���ҽ� ���� �ý����� �����ڸ� ��ȯ�մϴ�.
	 */
	static ResourceSystem& GetResourceSystem() { return *ResourceSystem_.get(); }


private:
	/**
	 * ������ ��Ʈ ���丮�Դϴ�.
	 */
	static std::string RootDirectory_;


	/**
	 * ���� ������ �����ϴ� ������ �ý����Դϴ�.
	 */
	static std::unique_ptr<WindowSystem> WindowSystem_;


	/**
	 * ���� ������ �����ϴ� ���� �ý����Դϴ�.
	 */
	static std::unique_ptr<RenderSystem> RenderSystem_;


	/**
	 * ���� ������ �����ϴ� �Է� �ý����Դϴ�.
	 */
	static std::unique_ptr<InputSystem> InputSystem_;


	/**
	 * ���� ������ �����ϴ� ���ҽ� �ý����Դϴ�.
	 */
	static std::unique_ptr<ResourceSystem> ResourceSystem_;
};