/*
// Files
*/

#ifndef _GX_SYSTEM_FILES_HEADER_
#define _GX_SYSTEM_FILES_HEADER_

/** Headers **/
#include <Common.hpp>
#include <string>
#include <string_view>

_GX_BEGIN

/**
 * File data
 **/
struct File
{
    std::string_view sPath;
    std::string sData;
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