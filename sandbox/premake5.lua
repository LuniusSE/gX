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

    objdir "%{wks.location}/.build/obj/%{prj.name}"
    targetdir "%{wks.location}/.build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "%{wks.location}/thirdparty",
        "%{wks.location}/platform",
        "%{wks.location}/core",
        "%{wks.location}/core/common"
    }

    links {
        "gXtp-glad",
        "gXtp-glfw",
        "gXtp-stb",
        "gXtp-glm",
        "gX-Core",
        "gX-Platform"
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