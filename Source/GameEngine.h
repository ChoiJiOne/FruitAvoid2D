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

// @third party code - BEGIN
#include <SDL2/SDL.h>
#include <json/json.hpp>
#include <spdlog/spdlog.h>
#include <stb/stb_image.h>
#include <stb/stb_truetype.h>
// @third party code - END

