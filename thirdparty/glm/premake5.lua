project "gXtp-glm"
	kind "StaticLib"
	language "C++"

    objdir "../../.build/obj/%{prj.name}"
    targetdir "../../.build/%{prj.name}"

	files {
        "**.hpp",
        "**.h",
        "**.inl",
        "**.cpp",
        "**.c"
    }
    
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"