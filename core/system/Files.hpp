/*
// Files
*/

#ifndef _GX_SYSTEM_FILES_HEADER_
#define _GX_SYSTEM_FILES_HEADER_

/** Headers **/
#include <Common.hpp>
#include <string>

_GX_BEGIN

/**
 * Useful file information
 *  File = ReadFile(_sPath)
 **/
struct File
{
    const char* sPath;
    char* sData;
    int nLines;
    int nCharacters;
};

/** File Options **/
enum class FileOptions
{
    Read,
    Overwrite,
    Append,
    Delete,
};

/*! @brief Wrapper of std::filesystem::path
 * 
 * @param[in] _sPath Relative Path
 * @returns Absolute Path
 **/
std::string FindPath(const char* _sPath);

/*! @brief Open file
 * TODO: Impl
**/
Status OpenFile(File& _fFile, FileOptions _eOptions);

_GX_END

#endif