project "gX-Core"
    kind "StaticLib"
    language "C++"

    dependson {
        "gX-ThirdParty"
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
        "glfw",
        "GL",
        "lua",
        "dl",
        "gX-ThirdParty"
    }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"