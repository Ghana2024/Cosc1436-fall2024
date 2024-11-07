

#include <iostream>
#include <string>
#include <cmath>

char choice; 
do
 {
    choice = displayMainMenu(); 
    switch (choice)
     { 
case 'a': std::cout << "You selected Option 1." << std::endl; // Add code for Option 1 here break; 
 case 'b': std::cout << "You selected Option 2." << std::endl; // Add code for Option 2 here break; 
case 'c': std::cout << "Quitting the program. Goodbye!" << std::endl;
 break;
     } 
   
} while (choice != 'c');  return 0;


// Function to prompt the user for numbers 
int getNumbers(int numbers[], int maxSize)
{
    int count = 0;
    int value;
    while (count < maxSize)
    {
        std::cout << "Enter an integer (0 to stop): ";
        std::cin >> value;
        if (value == 0)
        {
            break; // Stop if the user enters 0 
        } else if (value < 0)
        {
            std::cout << "Error: Negative values are not allowed." << std::endl;
        } else
        {
            numbers[count] = value; // Store the valid value count++;
        }
    } return count; // Return the number of valid entries }

}



int getNumbers(int numbers[], int maxSize)
{
    int count = 0;
    int value;
    while (count < maxSize)
    {
        std::cout << "Enter an integer (0 to stop): ";
        std::cin >> value;
        if (value == 0)
        {
            break; // Stop if the user enters 0 
        } else if (value < 0)
        {
            std::cout << "Error: Negative values are not allowed." << std::endl;
        } else
        {
            numbers[count] = value; // Store the valid value count++;
        }
    } return count; // Return the number of valid entries
}

// Function to display the main menu and get user's choice 
char displayMainMenu()
{
    char choice;
    std::cout << "Main Menu" << std::endl;
    std::cout << "A. Option 1" << std::endl;
    std::cout << "B. Option 2" << std::endl;
    std::cout << "C. Quit" << std::endl;
    do
    {
        std::cout << "Enter your choice (A, B, C): ";
        std::cin >> choice; choice = std::tolower(choice);
        if (choice != 'a' && choice != 'b' && choice != 'c')
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'a' && choice != 'b' && choice != 'c');
    
    return choice;
}



int main()
{
    std::cout << "Welcome to the number entry program!" << std::endl;
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int count;
    count = getNumbers(numbers, MAX_SIZE);
    std::cout << "You entered " << count << " valid numbers." << std::endl; // You can use the numbers array for further calculations here return 0


    char choice;
    do
    {
        choice = displayMainMenu();
        switch (choice)
        {
            case 'a': std::cout << "You selected Option 1." << std::endl; // Add code for Option 1 here break; 
            case 'b': std::cout << "You selected Option 2." << std::endl; // Add code for Option 2 here break; 
            case 'c': std::cout << "Quitting the program. Goodbye!" << std::endl;
                break;
        }
    } while (choice != 'c'); return 0;

}


