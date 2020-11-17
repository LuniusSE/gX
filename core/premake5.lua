project "gX-Core"
    kind "StaticLib"
    language "C++"

    dependson {
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm"
    }

    objdir "%{wks.location}/.build/obj/%{prj.name}"
    targetdir "%{wks.location}/.build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "%{wks.location}/thirdparty",
        "%{wks.location}/core",
        "%{wks.location}/core/core"
    }

    links {
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm"
    }

    filter "system:linux"
        links { "GL", "dl" }

    filter "system:windows"
        links { "opengl32" }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"