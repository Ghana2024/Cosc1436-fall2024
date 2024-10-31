/* Program title:Lab 3
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// Function to prompt user for falling time
int getFallingTime() 
{
    int time;
    do {
        cout << "Please enter the number of seconds from (1-60): ";
        cin >> time;
        if (time < 1 || time > 60) 
        {
            cout << "Error: Please enter correct value between 1 and 60." << endl;
        }
    } while (time < 1 || time > 60);
    return time;
}

// Function to calculate falling distance in meters
double calculateFallingDistance(int time) 
{
    const double g = 9.8; // Acceleration due to gravity with unit m/s^2
    double distance = 0.5 * g * pow(time, 2);
    return distance; 
}

// Function to convert meters to feet
 double convertToFeet(double meters)
 {
    const double conversionFactor = 3.28084;
    meters *= conversionFactor;
    return meters;
 }

// Selection of feet or meter
 void showFallingDistances(int totalTime, char unit)
  {
        cout << setw(6) << "Seconds" << setw(20) << "Distance ("
            << (unit == 'f' ? "ft" : "m") << ")" << endl;
        cout << "===============================" << endl;
        for (int time = 1; time <= totalTime; ++time)
        {
            double distance = calculateFallingDistance(time);
            if (unit == 'f')
            {
                distance = convertToFeet(distance); // Convert to feet if unit is 'f'
            }
            cout << setw(6) << time << setw(20) << fixed << setprecision(2) << distance << endl;
        }
  }

// Function to prompt user for unit of measurement feet or meters
char getUnitOfMeasurement() 
{
    char unit;
    do {
        cout << "Do you want the results in meters or feet?: ";
        cin >> unit;
        unit = tolower(unit); // Capital Letter to change into Small Letter
        if (unit != 'f' && unit != 'm') 
        {
            cout << "Error: Please enter 'f' for feet or 'm' for meters." << endl;
        }
    } while (unit != 'f' && unit != 'm');
    return unit;
}

int main()
{
    //Display Programmer Title, My Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 3 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

  // Function call
   int fallingTime = getFallingTime();
   double distance = calculateFallingDistance(fallingTime);
   char unit = getUnitOfMeasurement();
   showFallingDistances(fallingTime, unit);
return 0;
}