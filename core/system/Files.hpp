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

/*! @brief Read region of a file
 * TODO: Impl
 * 
 * #beginregion VertexShader
 * ...
 * ...
 * #endregion
 * 
**/
Status ReadRegion(File& _fFile, std::string& _sRegion);

_GX_END

#endif