project "gXtp-stb"
	kind "StaticLib"
	language "C"

    objdir "%{wks.location}/.build/obj/%{prj.name}"
    targetdir "%{wks.location}/.build/%{prj.name}"

	includedirs { "%{wks.location}/thirdparty" }

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