project "gX-Sandbox"
    kind "ConsoleApp"
    language "C++"

    dependson {
        "gXtp-glad"
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm",
        "gX-Platform",
        "gX-Core"
    }

    objdir "../.build/obj/%{prj.name}"
    targetdir "../.build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "../thirdparty",
        "../thirdparty/glfw/include/",
        "../core",
        "../core/common"
    }

    links {
        "GL",
        "gXtp-glad"
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm",
        "gX-Core"
    }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"