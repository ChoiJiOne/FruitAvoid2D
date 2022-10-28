workspace "FruitAvoid2D"

    configurations { 
        "Debug",
        "Release",
        "Shipping",
    }

    platforms {
        "Win64"
    }

    location "%{wks.name}"

    engine="%{wks.location}/../Engine"

    thirdparty="%{engine}/ThirdParty"

    game="%{wks.location}/../Game"

    project "Engine"
        kind "StaticLib"

        language "C++"

        cppdialect "C++17"

        includedirs {
            "%{engine}/Source",

            "%{thirdparty}/Include",
        }

        files {
            "%{engine}/Source/*",

            "%{thirdparty}/Include/Box2D/*",

            "%{thirdparty}/Include/glm/*",
            "%{thirdparty}/Include/glm/detail/*",
            "%{thirdparty}/Include/glm/ext/*",
            "%{thirdparty}/Include/glm/gtc/*",
            "%{thirdparty}/Include/glm/gtx/*",
            "%{thirdparty}/Include/glm/simd/*",

            "%{thirdparty}/Include/json/*",

            "%{thirdparty}/Include/SDL2/*",

            "%{thirdparty}/Include/spdlog/*",
            "%{thirdparty}/Include/spdlog/cfg/*",
            "%{thirdparty}/Include/spdlog/details/*",
            "%{thirdparty}/Include/spdlog/fmt/*",
            "%{thirdparty}/Include/spdlog/fmt/bundled/*",
            "%{thirdparty}/Include/spdlog/sinks/*",
        }

        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

            links {
                "%{thirdparty}/Debug/box2d.lib",
                "%{thirdparty}/Debug/SDL2.lib",
                "%{thirdparty}/Debug/SDL2main.lib",
                "%{thirdparty}/Debug/SDL2_image.lib",
                "%{thirdparty}/Debug/SDL2_mixer.lib",
                "%{thirdparty}/Debug/SDL2_net.lib",
                "%{thirdparty}/Debug/SDL2_ttf.lib",
            }

        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
            
            links {
                "%{thirdparty}/Release/box2d.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_image.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
                "%{thirdparty}/Release/SDL2_ttf.lib",
            }
        
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "%{thirdparty}/Release/box2d.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_image.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
                "%{thirdparty}/Release/SDL2_ttf.lib",
            }

    project "Game"
        kind "ConsoleApp"

        language "C++"

        cppdialect "C++17"

        links {"Engine"}

        includedirs {
            "%{engine}/Source",
            "%{thirdparty}/Include",
            "%{game}/Source",
        }

        files {
            "%{game}/Source/*",
            "%{game}/Content/*",
        }

        filter "configurations:Debug"
            defines { "DEBUG" }
            runtime  "Debug"
            optimize "Off"
            symbols "On"
            debugdir "%{thirdparty}/Debug"

            links {
                "%{thirdparty}/Debug/box2d.lib",
                "%{thirdparty}/Debug/SDL2.lib",
                "%{thirdparty}/Debug/SDL2main.lib",
                "%{thirdparty}/Debug/SDL2_image.lib",
                "%{thirdparty}/Debug/SDL2_mixer.lib",
                "%{thirdparty}/Debug/SDL2_net.lib",
                "%{thirdparty}/Debug/SDL2_ttf.lib",
            }

        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            optimize "On"
            symbols "On"
            debugdir "%{thirdparty}/Release"
            
            links {
                "%{thirdparty}/Release/box2d.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_image.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
                "%{thirdparty}/Release/SDL2_ttf.lib",
            }
        
        filter "configurations:Shipping"
            defines { "SHIPPING" }
            runtime "Release"
            optimize "Full"
            symbols "Off"
            debugdir "%{thirdparty}/Release"

            links {
                "%{thirdparty}/Release/box2d.lib",
                "%{thirdparty}/Release/SDL2.lib",
                "%{thirdparty}/Release/SDL2main.lib",
                "%{thirdparty}/Release/SDL2_image.lib",
                "%{thirdparty}/Release/SDL2_mixer.lib",
                "%{thirdparty}/Release/SDL2_net.lib",
                "%{thirdparty}/Release/SDL2_ttf.lib",
            }
