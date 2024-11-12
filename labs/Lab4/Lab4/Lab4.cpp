/* Program title:Lab 4
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int MAX_NUMBERS = 100;// Maximum number of integers that can be stored
// Function to prompt the user for numbers and store them in the array
int promptForNumbers(int numbers[], int maxSize) 
{
    int count = 0;// Counter for the number of valid entries
    int value;
    while (count < maxSize) 
    {
        cout << "Enter an integral number (0 to stop): ";
        cin >> value;
        if (cin.fail()) 
        {
            cin.clear(); // clear the error 
            cin.ignore(10000, '\n'); // discard invalid input
            cout << "Error: Please enter a valid integral number." << endl;
            continue;
        }
        if (value == 0) 
        {
            break;
        } else if (value < 0) 
        {
            cout << "Error: Negative values are not allowed." << endl;
        } else 
        {
            numbers[count++] = value;// Store valid values in the array
        }
    }
    return count;// Return the number of valid entries
}

// Function to display the main menu and get the user's choice
char displayMenu() 
{
    char choice;
    cout << "\nMain Menu:" << endl;
    cout << "1. Display values" << endl;
    cout << "2. Add more values" << endl;
    cout << "3. Get largest value" << endl;
    cout << "4. Get smallest value" << endl;
    cout << "5. Get sum of values" << endl;
    cout << "6. Get mean of values" << endl;
    cout << "Q. Quit" << endl;
    cout << "Select an option: ";
    cin >> choice;
    return toupper(choice);// Convert choice to uppercase to handle case insensitivity
}

// Function where takes the array of numbers as input.
//Returns the largest value in the array.
int getLargestValue(const int numbers[], int count) 
{
    int largest = numbers[0];
    for (int i = 1; i < count; ++i) 
    {
        if (numbers[i] > largest) 
        {
            largest = numbers[i];
        }
    }
    return largest;
}

// Function where takes the array of numbers as input.
//Returns the smallest value in the array.
int getSmallestValue(const int numbers[], int count) 
{
    int smallest = numbers[0];
    for (int i = 1; i < count; ++i) 
    {
        if (numbers[i] < smallest) 
        {
            smallest = numbers[i];
        }
    }
    return smallest;
}

// Function to get the sum of values in the array
int getSumOfValues(const int numbers[], int count) 
{
    int sum = 0;
    for (int i = 0; i < count; ++i) 
    {
        sum += numbers[i];
    }
    return sum;
}

// Function to get the mean of values in the array
//Returns the mean value.
double getMeanOfValues(const int numbers[], int count) 
{
    return static_cast<double>(getSumOfValues(numbers, count)) / count;
}

// Function to display the values in the array,showing 10 values per line.
void displayValues(const int numbers[], int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0) //Calculation to print 10 values per line
        {
            cout << endl;
        }
    }
    cout << endl;
}

// Function to add more values to the array
int addMoreValues(int numbers[], int count, int maxSize) 
{
    int value;
    while (count < maxSize) 
    {
        cout << "Enter an integral number (0 to stop): ";
        cin >> value;
        if (cin.fail()) 
        {
            cin.clear(); // clear the error flag
            cin.ignore(10000, '\n'); // discard invalid input
            cout << "Error: Please enter a valid integral number." << endl;
            continue;
        }
        if (value == 0) 
        {
            break;
        } else if (value < 0) 
        {
            cout << "Error: Negative values are not allowed." << endl;
        } else 
        {
            numbers[count++] = value;
        }
    }
    return count;
}

//Function to handle the menu choices takes the user’s choice, the array of numbers, and the count of numbers as input.
void handleMenuFunction(char choice, int numbers[], int& count) 
{
    switch (choice) 
    {
        case '1':
            displayValues(numbers, count);
            break;
        case '2':
            count = addMoreValues(numbers, count, MAX_NUMBERS);
            break;
        case '3':
            if (count > 0) 
            {
                cout << "Largest value: " << getLargestValue(numbers, count) << endl;
            } else 
            {
                cout << "No values entered." << endl;
            }
            break;
        case '4':
            if (count > 0) 
            {
                cout << "Smallest value: " << getSmallestValue(numbers, count) << endl;
            } else {
                cout << "No values entered." << endl;
            }
            break;
        case '5':
            cout << "Sum of values: " << getSumOfValues(numbers, count) << endl;
            break;
        case '6':
            if (count > 0) 
            {
                cout << "Mean of values: " << fixed << setprecision(4) << getMeanOfValues(numbers, count) << endl;
            } else 
            {
                cout << "No values entered." << endl;
            }
            break;
        case 'Q':
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Error: Invalid option. Please try again." << endl;
    }
}

int main() 
{
    //Display Program Title, My Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 4 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    cout << "Welcome to the Number Management Program!" << endl;
    int numbers[MAX_NUMBERS]; // Array to store the numbers
    int count = promptForNumbers(numbers, MAX_NUMBERS); // Get initial numbers from the user

    while (true) 
    {
        char choice = displayMenu();// Display menu and get user's choice
        handleMenuFunction(choice, numbers, count);// Handle the menu choice
    }
}

