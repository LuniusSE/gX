# Compiling

<h3>Linux</h3>

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

<h4>Support for other platforms isn't guaranteed yet.</h4>

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
