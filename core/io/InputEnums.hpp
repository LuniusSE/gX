/*
// Input Enum
*/

#ifndef _GX_IO_INPUT_ENUMS_
#define _GX_IO_INPUT_ENUMS_

/** Includes **/
#include <Common.hpp>

_GX_BEGIN

/** Input Axises for default InputDevices **/

/**
 * 
 **/
enum MouseAxises
{
    Mouse_X,
    Mouse_Y
};

/**
 * 
 **/
enum KeyboardAxises
{
};

/**
 * 
 **/
typedef enum class Action
{
    Released,
    Pressed,

    // Keys Only
    Repeat
}State;

/**
 * 
 **/
enum class Buttons
{
};

/**
 * 
 **/
enum class Keys
{
};

_GX_END

#endif