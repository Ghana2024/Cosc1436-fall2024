/* Program title:Lab 3 
 Ghana Dahal 
COSC 1436 Fall 2024*/

/*#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

// Function to prompt user for falling time
int getFallingTime() {
    int time;
    do {
        std::cout << "Enter the falling time in seconds (1-60): ";
        std::cin >> time;
        if (time < 1 || time > 60) {
            std::cout << "Error: Please enter a value between 1 and 60." << std::endl;
        }
    } while (time < 1 || time > 60);

    return time;
}

// Function to calculate falling distance in meters
double calculateFallingDistance(int time) {
    const double g = 9.8; // Acceleration due to gravity in m/s^2
    return 0.5 * g * std::pow(time, 2);
}

// Function to prompt user for unit of measurement
char getUnitOfMeasurement() {
    char unit;
    do {
        std::cout << "Enter the unit of measurement (f for feet, m for meters): ";
        std::cin >> unit;
        unit = std::tolower(unit);
        if (unit != 'f' && unit != 'm') {
            std::cout << "Error: Please enter 'f' for feet or 'm' for meters." << std::endl;
        }
    } while (unit != 'f' && unit != 'm');

    return unit;
}
// Function to convert meters to feet
double convertToFeet(double meters) 
{
    const double conversionFactor = 3.28084;
    return meters * conversionFactor;
}
//// Function to calculate falling distance
//double calculateFallingDistance(int time)
//{
//    const double g = 9.8; // Acceleration due to gravity in m/s^2
//    return 0.5 * g * std::pow(time, 2);
//}
// Function to show falling distance for each second up to given time
//void showFallingDistances(int totalTime) {
//    std::cout << std::setw(6) << "Time" << std::setw(20) << "Distance Fallen (m)" << std::endl;
//    std::cout << "---------------------------------" << std::endl;
//
//    for (int t = 1; t <= totalTime; ++t) {
//        double distance = calculateFallingDistance(t);
//        std::cout << std::setw(6) << t << std::setw(20) << std::fixed << std::setprecision(2) << distance << std::endl;
//    }
//}
// Function to show falling distances in the chosen unit
void showFallingDistances(int totalTime, char unit) {
    std::cout << std::setw(6) << "Time" << std::setw(20) << "Distance Fallen ("
        << (unit == 'f' ? "ft" : "m") << ")" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    for (int t = 1; t <= totalTime; ++t) {
        double distance = calculateFallingDistance(t);
        if (unit == 'f') {
            distance *= 3.28084; // Convert meters to feet
        }
       // std::cout << std::setw(6) << t << std::setw(20) << std::fixed << std::setprecision(2) << distance << std::endl;
    //}
   // for (int t = 1; t <= totalTime; ++t) {
      //  double distance = calculateFallingDistance(t);
        else if (unit == 'f') {
            distance = convertToFeet(distance); // Convert to feet if unit is 'f'
        }
        std::cout << std::setw(6) << t << std::setw(20) << std::fixed << std::setprecision(2) << distance << std::endl;
    }
}

int main()
{
    //Display Program Title, My Name, Course and Semester
    //cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 3 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    //std::cout << "Welcome to the Falling Time Calculator!" << std::endl;
    int fallingTime = getFallingTime();
   // std::cout << "Falling time entered: " << fallingTime << " seconds" << std::endl;
   // std::cout << "Welcome to the Falling Distance Calculator!" << std::endl;

    //int fallingTime = getFallingTime(); // Assuming you have implemented getFallingTime() as discussed before
   // int fallingTime = getFallingTime();
    double distance = calculateFallingDistance(fallingTime);
    std::cout << "Falling distance for " << fallingTime << " seconds is " << distance << " meters" << std::endl;
    //showFallingDistances(fallingTime);

    //std::cout << "Welcome to the Falling Distance Calculator!" << std::endl;
    
   // int fallingTime = getFallingTime();
    char unit = getUnitOfMeasurement();
    showFallingDistances(fallingTime, unit);


    std::cout << "Welcome to the Falling Distance Calculator!" << std::endl;

    //int fallingTime = getFallingTime();
    //char unit = getUnitOfMeasurement();
   // showFallingDistances(fallingTime, unit);
     
    return 0;

}*/

