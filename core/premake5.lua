project "gX-Core"
    kind "ConsoleApp"
    language "C++"

    objdir "../build/obj/%{prj.name}"
    targetdir "../build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    links {
        "glfw",
        "GLEW",
        "GL",
        "lua"
    }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        flags { "Symbols" }

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"