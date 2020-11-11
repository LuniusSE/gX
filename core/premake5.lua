project "gX-Core"
    kind "StaticLib"
    language "C++"

    dependson {
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm"
    }

    objdir "../.build/obj/%{prj.name}"
    targetdir "../.build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "../thirdparty",
        "../core",
        "common/"
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