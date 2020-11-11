project "gX-Sandbox"
    kind "ConsoleApp"
    language "C++"

    dependson {
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm",
        "gX-Core",
        "gX-Platform"
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
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm",
        "gX-Core"
    }

    filter "system:windows"
        links { "opengl32" }

    filter "system:linux"
        links { "X11", "GL", "dl" }
        linkoptions { "-pthread" }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"