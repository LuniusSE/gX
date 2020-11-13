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
std::string FindPath(const char* _sPath)
{
    return std::filesystem::path(_sPath).string();
}

_GX_END