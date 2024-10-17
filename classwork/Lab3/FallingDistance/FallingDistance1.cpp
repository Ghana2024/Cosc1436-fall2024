/* Program title:Lab 3
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
//#include <cctype>
using namespace std;

// Function to prompt user for falling time
int getFallingTime() 
{
    int time;
    do {
        cout << "Enter the falling time in seconds (1-60): ";
        cin >> time;
        if (time < 1 || time > 60) {
            cout << "Error: Please enter correct value between 1 and 60." << endl;
        }
    } while (time < 1 || time > 60);

    return time;
}

// Function to calculate falling distance in meters
double calculateFallingDistance(int time) 
{
    const double g = 9.8; // Acceleration due to gravity in m/s^2
    return 0.5 * g * pow(time, 2);
}
// Function to convert meters to feet
double convertToFeet(double meters)
{
    const double conversionFactor = 3.28084;
    return meters * conversionFactor;
}

void showFallingDistances(int totalTime, char unit) {
    cout << setw(6) << "Time" << setw(20) << "Distance Fallen ("
        << (unit == 'f' ? "ft" : "m") << ")" << endl;
    cout << "---------------------------------" << endl;

    for (int t = 1; t <= totalTime; ++t) {
        double distance = calculateFallingDistance(t);
        if (unit == 'f') {
            distance *= 3.28084; // Convert meters to feet
        }
        else if (unit == 'f') {
            distance = convertToFeet(distance); // Convert to feet if unit is 'f'
        }
        cout << setw(6) << t << setw(20) << fixed << setprecision(2) << distance << endl;
    }
}
// Function to prompt user for unit of measurement
char getUnitOfMeasurement() 
{
    char unit;
    do {
        cout << "Do you want the results in meters or feet?: ";
        cin >> unit;
        unit = tolower(unit);
        if (unit != 'f' && unit != 'm') {
            cout << "Error: Please enter 'f' for feet or 'm' for meters." << endl;
        }
    } while (unit != 'f' && unit != 'm');

    return unit;
}

int main()
{
    //Display Program Title, My Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 3 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;
   
int fallingTime = getFallingTime();
double distance = calculateFallingDistance(fallingTime);
char unit = getUnitOfMeasurement();
showFallingDistances(fallingTime, unit);

return 0;
}