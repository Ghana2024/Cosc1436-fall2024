// labs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    struct Movie
    {
        //Required
        string Title;

        // At least 0, minutes
        int RunLength;

        //Optional
        string Description;

        // >=1900
        int ReleaseYear;

        bool IsClassic;
    };

}
