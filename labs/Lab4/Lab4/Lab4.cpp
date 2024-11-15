/* Program title:Lab 4
 Ghana Dahal
COSC 1436 Fall 2024*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

/// @brief function is designed to prompt the user to input numbers, storing them in an array. 
/// It ensures that the number of inputs does not exceed the specified maximum size of the array.
/// @param numbers;an array of integers where the function will store the numbers input by the user. 
/// @param maxNumbersSize ; an integer where the maximum size of the numbers array.
/// The maximum number of integers the function can store.
/// @param startCount; indicates the number of elements already present in the array before the function starts adding new numbers.
/// @return count;the total number of numbers successfully stored in the array after the function completes. 
/// This includes any pre-existing numbers plus the new ones added by the function.
int promptForNumbers(int numbers[], int maxNumbersSize, int startCount = 0) 
{
    int count = startCount;// initial counter for the number of valid entries
    int value;
    while(count < maxNumbersSize) 
    {
        cout << "Enter an integral number (0 to stop): ";
        if (cin >> value)
        {
            if (value == 0)
            {
                break;
            } else if (value < 0)
            {
                cout << "Error: Negative values are not allowed." << endl;
            } 
            else
            {
                numbers[count++] = value;// Store valid values (i.e; elements) in the array
            }
        }
        else
        {
                cin.clear(); // clear the error 
                cin.ignore(maxNumbersSize, '\n'); // discard invalid input and space
                cout << "Error: Please enter a valid integral number." << endl;
                continue;
        }
    }
    return count;// Return the number of valid entries
}

///<Summary> Function to display the main menu and get the user's choice </summary>
char displayMenu() 
{
    char choice;
    cout << "\nMain Menu:" << endl;
    cout << setw(15) << setfill('=') << "" << setfill(' ') << endl;
    cout << "1. Display values" << endl;
    cout << "2. Add more values" << endl;
    cout << "3. Get largest value" << endl;
    cout << "4. Get smallest value" << endl;
    cout << "5. Get sum of values" << endl;
    cout << "6. Get mean of values" << endl;
    cout << "Q. Quit" << endl;
    cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Select an option 1 to 6 or Q for Exit the Program: ";
    cin >> choice;
    return toupper(choice);// Convert choice to uppercase to handle case insensitivity
}

///<Summary> Function where takes the array of numbers as input for largest number.</Summary>
///<parameter name= "const int numbers[]">The array of integers from which the function will find the largest value.</parameter>
///<parameter name= "int count">The number of elements in the numbers array.</parameter>
///<return name ="largestNumber">Get the largest element number in the array.</return>
int getLargestValue(const int numbers[], int count) 
{
    int largestNumber = numbers[0];//initializing largest the first element of the array numbers.
    for (int i = 1; i < count; ++i) 
    {
        if (numbers[i] > largestNumber) 
        {
            largestNumber = numbers[i];//updating largest if current element is greater.
        }
    }
    return largestNumber;
}

///<Summary> Function where takes the array of numbers as input for smallest number.</Summary>
///<parameter name= "const int numbers[]">The array of integers from which the function will find the smallest value.</parameter>
///<parameter name= "int count">The number of elements in the numbers array.</parameter>
///<return name ="smallestNumber">Get the smallest element number in the array.</return> 
int getSmallestValue(const int numbers[], int count) 
{
    int smallestNumber = numbers[0];//initializing smallest the first element of the array numbers.
    for (int i = 1; i < count; ++i) 
    {
        if (numbers[i] < smallestNumber) 
        {
            smallestNumber = numbers[i];//updating smallest if current element is lowest value.
        }
    }
    return smallestNumber;
}

// Function to get the sum of values in the array
int getSumOfValues(const int numbers[], int count) 
{
    int sum = 0;
    for (int i = 0; i < count; ++i) 
    {
        sum += numbers[i];//adding each element to sum
    }
    return sum;
}

// Function to get the mean of values in the array
//Returns the mean value.
double getMeanOfValues(const int numbers[], int count) 
{
    return static_cast<double>(getSumOfValues(numbers, count)) / count;
    //dividing the sum of the array elements that is converted to double/the number of elements.
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
/// @brief Function to add more values to the array
/// @param numbers 
/// @param count 
/// @param maxNumbersSize 
/// @return 
int addMoreValues(int numbers[], int count, int& maxNumbersSize)
{
    return promptForNumbers(numbers, maxNumbersSize, count);
}

/// @brief Function to handle the menu choices takes the user's choice.
/// @param choice 
/// @param numbers 
/// @param count 
/// @param maxSize 
void handleMenuFunction(char choice, int numbers[], int& count, int maxSize)// 
{
    switch (choice) 
    {
        case '1':
            cout << "\nThe numbers are ";
            displayValues(numbers, count);
            cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case '2':
            count = addMoreValues(numbers, count, maxSize);
            break;
        case '3':
                cout << "Largest value: " << getLargestValue(numbers, count) << endl;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case '4':
                cout << "Smallest value: " << getSmallestValue(numbers, count) << endl;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case '5':
            cout << "Sum of values: " << getSumOfValues(numbers, count) << endl;
            cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case '6':
                cout << "Mean of values: " << fixed << setprecision(4) << getMeanOfValues(numbers, count) << endl;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case 'Q':
            cout << "Exiting the program. Goodbye for this time!" << endl;
            cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            exit(0);
        default:
            cout << "Error: Invalid option. Please try again." << endl;
    }
}

/// @brief Main header file and entry of the program starting point.
/// @return choice with detail of the choice result.
int main() 
{
    //Display Program Title, My Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 4 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    //Diplaying message for program starting point
    cout << "Welcome to the Number Management Program!" << endl;
    const int maxNumberSize = 100;// Maximum number of integers that can be stored
    int numbers[maxNumberSize]; // Array to store the numbers
    int count = promptForNumbers(numbers, maxNumberSize); // Get initial numbers from the user
    while (true) 
    {
        char choice = displayMenu();// Display menu and get user's choice
        handleMenuFunction(choice, numbers, count, maxNumberSize);// Handle the menu choice
    }
}

