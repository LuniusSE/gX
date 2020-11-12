# Compiling

### Linux

```sh
$ ./build.sh
    Building configurations...
    Running action 'gmake2'...
    ...
    ...
    ...
    Done (...ms).
    ==== Building gX-ThirdParty (debug) ====
    ...
    ==== Building gX-Platform (debug) ====
    ...
    ==== Building gX-Core (debug) ====
    ...
    ==== Building gX-Sandbox (debug) ====
    ...
    ==== ... ====
    ...
```

if you get a permission denied error
```sh
$ chmod +x build.sh
```

### Visual Studio
Download [Premake5.exe](https://premake.github.io/download.html#v5)
```sh
> premake5 vs2019
    Building configurations...
    Running action 'vs2019'...
    ...
    ...
    ...
    Done (...ms).
```
Now you can open the solution file ***gX-Workspace.sln*** and compile

#### Support for other platforms isn't guaranteed yet.

# Small TODO List
 - Logging
 - Memory Usage / Leak Detector
 - Profiling
 - Memory Allocator
 - Files
    - Read/Write
    - Create/Delete
    - JSON
 - Events
 - Event Messanger
