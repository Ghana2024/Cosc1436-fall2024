/*
 * COSC 1436
 * Sample implementation
 * 
 * Provides console-related functions.
 */
#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

/// <summary>Defines possible console colors.</summary>
enum class ConsoleColor {
    Default = 0,

    DarkBlack = 40,
    DarkRed = 41,
    DarkGreen = 42,
    DarkYellow = 43,
    DarkBlue = 44,
    DarkMagenta = 45,
    DarkCyan = 46,
    DarkWHite = 47,

    Black = 90,
    Red = 91,
    Green = 92,
    Yellow = 93,
    Blue = 94,
    Magenta = 95,
    Cyan = 96,
    White = 97
};

void DisplayColor(ConsoleColor color)
{
    std::cout << "\033[" << (int)color << "m";
};

/// <summary>Displays an error message.</summary>
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    DisplayColor(ConsoleColor::Red);
    std::cout << "[ERROR] " << message << std::endl;
    DisplayColor(ConsoleColor::Default);
};

/// <summary>Displays a horizontal line.</summary>
/// <param name="width">Width of the line.</param>
void DisplayHorizontalLine(int width)
{
    std::cout << std::setfill('-');
    std::cout << std::setw(width) << "" << std::endl;
    std::cout << std::setfill(' ');
};

/// <summary>Reads a single character from the input.</summary>
/// <returns>The character read.</returns>
char ReadChar()
{    
    char input;
    std::cin >> input;

    return input;
};

/// <summary>Reads an integral value.</summary>
/// <param name="minimumValue">Minimum value.</param>
/// <param name="maximumValue">Maximum value.</param>
/// <returns></returns>
int ReadInt(int minimumValue = INT32_MIN, int maximumValue = INT32_MAX)
{
    int value;

    bool hasMinValue = minimumValue != INT32_MIN;
    bool hasMaxValue = maximumValue != INT32_MAX;

    do
    {
        std::cin >> value;

        if (value >= minimumValue && value <= maximumValue)
            return value;
        
        //Until C++ 20 and then use std::format
        std::ostringstream message;
        message << "Value must be ";
        
        if (hasMinValue && hasMaxValue)
            message << "between " << minimumValue << " and " << maximumValue;
        else if (hasMinValue)
            message << "at least " << minimumValue;
        else if (hasMaxValue)
            message << "at most " << maximumValue;

        DisplayError(message.str());

    } while (true);
};