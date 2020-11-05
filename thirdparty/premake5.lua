project "gX-ThirdParty"
    kind "StaticLib"
    language "C++"

    objdir "../build/obj/%{prj.name}"
    targetdir "../build/%{prj.name}"

    files {
        "**.cpp",
        "**.hpp"
    }

    links {

    }

    filter "configurations:Debug"
        defines { "GX_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "GX_RELEASE" }
        optimize "On"