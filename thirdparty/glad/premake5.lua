project "gXtp-glad"
	kind "StaticLib"
	language "C"

    objdir "../../.build/obj/%{prj.name}"
    targetdir "../../.build/%{prj.name}"

	files {
        "khrplatform.h",
        "glad.h",
        "glad.c"
    }

    filter "system:linux"
        links {
            "GL"
        }

    filter "system:windows"
        links {
            "opengl32"
        }
    
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"