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

    -- 소스 코드 경로를 지정합니다.
    source="%{wks.location}/../Source"

    -- 외부 확장 라이브러리의 경로를 지정합니다.
    thirdparty="%{wks.location}/../ThirdParty"

    -- FruitAvoid2D 프로젝트입니다.
    project "FruitAvoid2D"
        -- 프로젝트의 종류를 설정합니다.
        kind "ConsoleApp"

        -- 프로그래밍 언어를 설정합니다.
        language "C++"

        -- C++의 표준을 설정합니다.
        cppdialect "C++17"

        -- 프로젝트의 include 경로를 추가합니다.
        includedirs {
            "%{source}",
            "%{thirdparty}/Include",
        }

        -- 프로젝트의 file을 추가합니다.
        files {
            "%{source}/*",
            "%{thirdparty}/Include/SDL2/*",
            "%{thirdparty}/Include/json/*",
            "%{thirdparty}/Include/spdlog/*",
            "%{thirdparty}/Include/spdlog/cfg/*",
            "%{thirdparty}/Include/spdlog/details/*",
            "%{thirdparty}/Include/spdlog/fmt/*",
            "%{thirdparty}/Include/spdlog/fmt/bundled/*",
            "%{thirdparty}/Include/spdlog/sinks/*",
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
            defines { "NDEBUG" }
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
            defines { "NDEBUG" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
            }
