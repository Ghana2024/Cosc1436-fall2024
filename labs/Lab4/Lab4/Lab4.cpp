// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const int MAX_NUMBERS = 100;
int promptForNumbers(int numbers[], int maxSize) 
{
    int count = 0;
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
            numbers[count++] = value;
        }
    }
    return count;
}

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
    return toupper(choice);
}

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

int getSumOfValues(const int numbers[], int count) 
{
    int sum = 0;
    for (int i = 0; i < count; ++i) 
    {
        sum += numbers[i];
    }
    return sum;
}

double getMeanOfValues(const int numbers[], int count) 
{
    return static_cast<double>(getSumOfValues(numbers, count)) / count;
}

void displayValues(const int numbers[], int count) 
{
    for (int i = 0; i < count; ++i) 
    {
        cout << numbers[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}

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
    cout << "Welcome to the Number Management Program!" << endl;
    int numbers[MAX_NUMBERS];
    int count = promptForNumbers(numbers, MAX_NUMBERS);

    while (true) 
    {
        char choice = displayMenu();
        handleMenuFunction(choice, numbers, count);
    }
}

