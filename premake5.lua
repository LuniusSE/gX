workspace "gX-Workspace"
    architecture "x64"
    startproject "gX-Sandbox"
    cppdialect "C++17"
    linkgroups "On"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

include "thirdparty"

group ""
include "platform"
include "core"
include "sandbox"