project "gX-Sandbox"
    kind "ConsoleApp"
    language "C++"

    dependson {
        "gX-Core",
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
        "../core/common"
    }

    links {
        "glfw",
        "GL",
        "lua",
        "dl",
        "gX-ThirdParty",
        "gX-Core"
    }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"