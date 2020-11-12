project "gXtp-glad"
	kind "StaticLib"
	language "C"

    objdir "%{wks.location}/.build/obj/%{prj.name}"
    targetdir "%{wks.location}/.build/%{prj.name}"

	includedirs { "%{wks.location}/thirdparty" }

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