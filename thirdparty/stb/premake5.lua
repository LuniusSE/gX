project "gXtp-stb"
	kind "StaticLib"
	language "C"

    objdir "../../.build/obj/%{prj.name}"
    targetdir "../../.build/%{prj.name}"

	files {
        "stb_image.h",
        "stb_image.c"
    }
    
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"