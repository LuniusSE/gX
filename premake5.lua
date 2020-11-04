workspace "gX-Workspace"
    architecture "x64"
    startproject "gX-Core"

    configurations {
        "Debug",
        "Release"
    }

    flags {
        "MultiProcessorCompile"
    }

include "core"