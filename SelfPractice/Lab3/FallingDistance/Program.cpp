/*
 * COSC 1436
 * Lab 3
 * Sample implemention
 */
#include <iostream>
#include <iomanip>
#include <string>

#include "Console.h"

using namespace std;

/// <summary>Defines the available length units.</summary>
enum class LengthUnit
{
    Meters = 0,
    Feet,
};

/// <summary>Converts from meters to feet.</summary>
/// <param name="vaalue">Value to convert.</param>
/// <returns>Converted value.</returns>
double ConvertMetersToFeet ( double value )
{
    const double feetInMeters = 3.28084;

    return value * feetInMeters;
};

/// <summary>Calculates the falling distance for the given time.</summary>
/// <param name="seconds">Time interval, in seconds.</param>
/// <returns>Distance fallen, in meters.</returns>
double FallingDistance(int seconds)
{
    const double g = 9.8;

    return (0.5) * g * (seconds * seconds);
};

/// <summary>Gets the label for a given unit.</summary>
/// <param name="unit">Unit</param>
/// <param name="useShortLabel">True to use the short label.</param>
/// <returns>Label</returns>
string GetUnitLabel(LengthUnit unit, bool useShortLabel)
{
    switch (unit)
    {
        case LengthUnit::Feet: return useShortLabel ? "f" : "feet";
        case LengthUnit::Meters: return useShortLabel ? "m" : "meters";
    };

    return "";
};

/// <summary>Displays a table of falling distance.</summary>
/// <param name="seconds">Time falling, in seconds.</param>
/// <param name="unit">Unit to show the results in.</param>
void DisplayFallingDistance(int seconds, LengthUnit unit )
{
    cout << fixed << setprecision(2);

    cout << setw(10) << "Seconds" << setw(10) << "Distance" << endl;
    DisplayHorizontalLine(20);

    string unitLabel = GetUnitLabel(unit, true);

    for (int time = 1; time <= seconds; ++time)
    {
        double distance = FallingDistance(time);

        if (unit == LengthUnit::Feet)
            distance = ConvertMetersToFeet(distance);

        cout << setw(10) << time << setw(10) << distance << " " << unitLabel << endl;
    };
};

/// <summary>Displays program information.</summary>
void DisplayProgramInformation()
{
    cout << "Falling Distance (lab 3)" << endl;
    cout << "COSC 1436" << endl;
    cout << "Sample implementation" << endl;
    DisplayHorizontalLine(30);
    cout << endl;
};

/// <summary>Get the falling time, in seconds, from the user.</summary>
/// <returns>The time falling, in seconds.</returns>
int ReadFallingTime()
{
    cout << "Please enter the number of seconds? ";

    return ReadInt(1, 60);
};

/// <summary>Get the length unit, feet or meters, to use.</summary>
/// <returns>The unit selected.</returns>
LengthUnit ReadUnit()
{
    cout << "Do you want the results in (m)eters or (f)eet? " << endl;

    do
    {
        switch (ReadChar())
        {
            case 'F':
            case 'f': return LengthUnit::Feet;

            case 'M':
            case 'm': return LengthUnit::Meters;
        };

        DisplayError("Invalid option");
    } while (true);
};

// Entry point
int main()
{
    DisplayProgramInformation();

    int seconds = ReadFallingTime();
    LengthUnit unit = ReadUnit();

    DisplayFallingDistance(seconds, unit);
}