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
 * ������ �ʱ�ȭ/���� �ϴ� Ŭ�����Դϴ�.
 * �̶�, �ݵ�� �ʱ⿡ Init, �������� Quit �޼��带 ȣ���ؾ� �մϴ�.
 * �� Ŭ������ ���� Ŭ������, �ش� ���� �߰��ϸ� �ٷ� ����� �� �ֽ��ϴ�.
 */
class ToyEngine
{
public:
	/**
	 * ToyEngine�� �ʱ�ȭ�մϴ�.
	 */
	static void Init();


	/**
	 * ToyEngine�� �����մϴ�.
	 */
	static void Quit();
};