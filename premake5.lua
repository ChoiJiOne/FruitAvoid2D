-- FruitAvoid2D 작업 영역입니다.
workspace "FruitAvoid2D"
    -- 빌드 구성 요소입니다.
    configurations { 
        "Debug",
        "Release",
        "Shipping",
    }

    -- 빌드 플랫폼입니다.
    platforms {
        "Win64"
    }

    -- 작업 영역 경로를 지정합니다.
    location "%{wks.name}"

    -- 엔진 경로를 지정합니다.
    engine="%{wks.location}/../Engine"

    -- 외부 확장 라이브러리의 경로를 지정합니다.
    thirdparty="%{engine}/ThirdParty"

    -- 게임 경로를 지정합니다.
    game="%{wks.location}/../Game"

    -- 게임 엔진 프로젝트입니다.
    project "Engine"
        -- 게임 엔진 프로젝트의 종류를 설정합니다.
        kind "StaticLib"

        -- 게임 엔진 프로젝트의 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 프로젝트의 include 경로를 추가합니다.
        includedirs {
            -- 게임 엔진 소스를 추가합니다.
            "%{engine}/Source",

            -- 서드 파티 라이브러리 경로를 추가합니다.
            "%{thirdparty}/Include",
        }

        -- 프로젝트의 file을 추가합니다.
        files {
            -- 게임 엔진의 소스를 추가합니다.
            "%{engine}/Source/*",

            -- SDL2를 추가합니다.
            "%{thirdparty}/Include/SDL2/*",

            -- json을 추가합니다.
            "%{thirdparty}/Include/json/*",

            -- spdlog를 추가합니다.
            "%{thirdparty}/Include/spdlog/*",
            "%{thirdparty}/Include/spdlog/cfg/*",
            "%{thirdparty}/Include/spdlog/details/*",
            "%{thirdparty}/Include/spdlog/fmt/*",
            "%{thirdparty}/Include/spdlog/fmt/bundled/*",
            "%{thirdparty}/Include/spdlog/sinks/*",

            -- stb를 추가합니다.
            "%{thirdparty}/Include/stb/*",
        }

        -- Debug 모드일 때의 설정을 추가합니다.
        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

            links {
                "%{thirdparty}/Debug/SDL2d.lib",
                "%{thirdparty}/Debug/SDL2maind.lib",
            }

        -- Release 모드일 때의 설정을 추가합니다.
        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
            
            links {
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
            }
        
        -- Shipping 모드일 때의 설정을 추가합니다.
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
            }

    -- 게임 프로젝트입니다.
    project "Game"
        -- 게임 프로젝트의 종류를 설정합니다.
        kind "ConsoleApp"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 게임 프로젝트에 게임 엔진 프로젝트를 연결합니다.
        links {"Engine"}

        -- 프로젝트의 include 경로를 추가합니다.
        includedirs {
            -- 게임 엔진 소스를 추가합니다.
            "%{engine}/Source",

            -- 서드 파티 라이브러리 경로를 추가합니다.
            "%{thirdparty}/Include",

            -- 게임 소스 코드를 추가합니다.
            "%{game}/Source",
        }

        -- 프로젝트의 file을 추가합니다.
        files {
            "%{game}/Source/*",
            "%{game}/Content/*",
        }

        -- Debug 모드일 때의 설정을 추가합니다.
        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

            links {
                "%{thirdparty}/Debug/SDL2d.lib",
                "%{thirdparty}/Debug/SDL2maind.lib",
            }

        -- Release 모드일 때의 설정을 추가합니다.
        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
            
            links {
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
            }
        
        -- Shipping 모드일 때의 설정을 추가합니다.
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
            }
