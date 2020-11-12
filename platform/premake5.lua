project "gX-Platform"
    kind "StaticLib"
    language "C++"

    dependson {
        "gX-Core"
    }

    objdir "%{wks.location}/.build/obj/%{prj.name}"
    targetdir "%{wks.location}/.build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    filter "system:linux"
        defines { "GX_SYS_LINUX" }
        links {
            "X11"
        }

    filter "system:windows"
        defines { "GX_SYS_WINDOWS" }
        links {
        }

    filter "system:macosx"
        defines { "GX_SYS_MACOSX" }
        links {
            "X11"
        }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"