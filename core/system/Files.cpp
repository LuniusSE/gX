/*
// Files
*/
#include "Files.hpp"

/** Headers **/
#include <filesystem>

_GX_BEGIN

/**
 * /Files.cpp
 *  FindPath Implementation
 **/
const char* FindPath(const char* _sPath)
{
    return std::filesystem::path(_sPath).c_str();
}

_GX_END