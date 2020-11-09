workspace "gX-Workspace"
    architecture "x64"
    startproject "gX-Core"
    cppdialect "C++17"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

include "thirdparty"
include "platform"
include "core"