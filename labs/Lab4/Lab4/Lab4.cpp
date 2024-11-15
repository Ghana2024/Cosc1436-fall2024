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
/// @param numbers[];an array of integers where the function will store the numbers input by the user. 
/// @param maxNumbersSize ; an integer where the maximum size of the numbers array can store.
/// @param startCount; indicates the number of elements present, in the array before the function starts at 0 adding new numbers.
/// @return count;the total number of numbers successfully stored in the array after the function completes. 
/// This includes any pre-existing numbers plus the new ones added by the function.
int promptForNumbers(int numbers[], int maximumNumbersSize, int startCount = 0) 
{
    int count = startCount;// initial counter for the number of valid entries
    int value;
    while(count < maximumNumbersSize) 
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
                cin.ignore(maximumNumbersSize, '\n'); // discard invalid input and space
                cout << "Error: Please enter a valid integral number." << endl;
                continue;
        }
    }
    if (count >= maximumNumbersSize)// checking the limit.
    {
        cout << "You exceed the entering number limit." << endl;
    }
    return count;// Return the number of valid entries
}

/// @brief;function to display the main menu and get the user's choice 
/// @return;the function returns the user's choice as an uppercase character.
char displayMenu() 
{
    char choice;
    cout << "\nMain Menu:" << endl;
    cout << setw(15) << setfill('=') << "" << setfill(' ') << endl;
    cout << "D. Display values" << endl;
    cout << "A. Add more values" << endl;
    cout << "L. Get largest value" << endl;
    cout << "S. Get smallest value" << endl;
    cout << "T. Get total sum of values" << endl;
    cout << "M. Get mean of values" << endl;
    cout << "Q. Quit" << endl;
    cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
    cout << "Select an option or Q for Exit the Program: ";
    cin >> choice;
    return toupper(choice);// convert choice to uppercase to handle case insensitivity
}

/// @brief; the function getLargestValue() finds and returns the largest value in an array of integers.
/// @param const int numbers;const keyword indicates that the array elements will not be modified by the function.
/// @param count;the number of elements in the array. 
/// @return largestNumber;function returns an integer, which is the largest value found in the array. 
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

/// @brief;the function getSmallestValue() finds and returns the smallest value in an array of integers.
/// @param const int numbers[];const keyword indicates that the array elements will not be modified by the function. 
/// @param count;the number of elements in the array.
/// @return smallestNumber; function returns an integer, which is the largest value found in the array.
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

/// @brief;function getSumOfValues() calculates and returns the sum of all elements in an array of integers.
/// @param const int numbers[];indicates that the function will not modify the array elements. 
/// @param count;the number of elements in the array. 
/// @return;function returns an integer, which is the sum of all the values in the array.
int getSumOfValues(const int numbers[], int count) 
{
    int sum = 0;
    for (int i = 0; i < count; ++i) 
    {
        sum += numbers[i];//adding each element
    }
    return sum;
}

/// @brief;function getMeanOfValues() calculates and returns the mean (average) of all elements in an array.
/// @param const int numbers[];const type integer indicates that the function will not modify the array elements. 
/// @param count; shows the number of elements in the array. 
/// @return a double,the mean of the values in the array. 
double getMeanOfValues(const int numbers[], int count) 
{
    return static_cast<double>(getSumOfValues(numbers, count)) / count;
    //dividing the sum of the array elements that is converted to double/the number of elements.
}

/// @brief;function displayValues() prints all elements of an array of integers. 
/// Which displaying up to 10 values per line for better readability.
/// @param const int numbers[]; const type int indicates,the function will not modify the array elements.  
/// @param count;counts the number of elements in the array.
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
/// @brief;function addMoreValues() add more values to an existing array of integers
/// which by calling another function, promptForNumbers().
/// @param int numbers[];an array of integers where new values will be added.
/// @param count; count the current number of elements in the array. 
/// @param maxNumbersSize; a reference to an integer representing the maximum size of the array. 
/// reference allows the function to modify the original variable when needed.
/// @return; an integer, which is likely the new count of elements in the array after adding more values.
int addMoreValues(int numbers[], int count, int& maximumNumbersSize)
{
    if (count >= maximumNumbersSize)
    {
        cout << "You cannot add more than 100 values. The maximun number reach the limit." << endl;
        return count; // Return the current count without adding new values
    }
    return promptForNumbers(numbers, maximumNumbersSize, count);
}

/// @brief Function to handle the menu choices takes the user's choice.
/// @param choice;user's menu choice which determines the action to be performed. 
/// @param numbers[];an array of integers that stores the values to be processed.
/// @param int& count;A reference to an integer representing the current number of elements in the array. 
/// This allows the function to update the count if more values are added. 
/// @param maxValuesSize;The maximum size,how many values can be stored.
void handleMenuFunction(char choice, int numbers[], int& count, int maximumValuesSize) 
{
    switch (choice) 
    {
        case 'D':
            cout << "\nThe numbers are ";
            displayValues(numbers, count);
            cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case 'A':
            count = addMoreValues(numbers, count, maximumValuesSize);
            break;
        case 'L':
                cout << "Largest value: " << getLargestValue(numbers, count) << endl;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case 'S':
                cout << "Smallest value: " << getSmallestValue(numbers, count) << endl;
                cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case 'T':
            cout << "Sum of values: " << getSumOfValues(numbers, count) << endl;
            cout << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            break;
        case 'M':
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

/// @brief; main header with programing title and course info,and also the starting point of the program.
/// @return; function returns an integer with detail of the choice result.
int main() 
{
    //Display Basic Program Title,Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 4 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;

    //Diplaying message for program starting point
    cout << "Welcome to the Number Management Program!" << endl;
    const int maximumNumberSize = 100;// Maximum number of integers that can be stored
    int numbers[maximumNumberSize]; // Array to store the numbers
    int count = promptForNumbers(numbers, maximumNumberSize); // Get initial numbers from the user
    while (true) 
    {
        char choice = displayMenu();// Display menu and get user's choice
        handleMenuFunction(choice, numbers, count, maximumNumberSize);// Handle the menu choice
    }
}

