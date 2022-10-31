#include "Color.h"
#include "CommandLine.h"
#include "CrashReport.h"
#include "Font.h"
#include "GameFramework.h"
#include "Input.h"
#include "Graphics2D.h"
#include "Macro.h"
#include "Random.h"
#include "Text.h"
#include "Texture.h"
#include "Timer.h"
#include "Vector.h"
#include "Window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <Box2D/box2d.h>
#include <json/json.hpp>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>


/**
 * 엔진을 초기화/해제 하는 클래스입니다.
 * 이때, 반드시 초기에 Init, 마지막에 Quit 메서드를 호출해야 합니다.
 * 이 클래스는 정적 클래스로, 해더 선언만 추가하면 바로 사용할 수 있습니다.
 */
class ToyEngine
{
public:
	/**
	 * ToyEngine을 초기화합니다.
	 */
	static void Init();


	/**
	 * ToyEngine을 해제합니다.
	 */
	static void Quit();
};