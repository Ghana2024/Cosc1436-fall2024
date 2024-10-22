
#include <iostream>
#include <string>
#include <iomanip>

//function overloading -2 or more functions have the same name but different signatures

/// @brief Read an integer from console
/// @param message Message to display
/// @return Integral value provided by user
int ReadInt(std::string message)
{
    //Display message
    //cout int value and return
       
        std::cout << message;

        int value;
        std::cin >> value;

        return value;
}
int ReadInt(std::string message, int minValue, int maxValue)
{
    int value;
    do {
        value = ReadInt(message);
        if (value <minValue || value > maxValue)
        {
            std::cout << "value must be between" << minValue << " and " << maxValue <<std::endl;
        }
    } while (value < minValue || value > maxValue);
        return value;
}
int ReadInt(std::string message, int minValue)
{
    return ReadInt(message, minValue, INT32_MAX);
     /*int value;
    do {

       value = ReadInt(message);
        if (value <minValue)
        {
            std::cout << "value must be between" << minValue << std::endl;
        }
    } while (value < minValue);
        return value;*/
}

struct Employee {
    int Id;
    std::string Name;

    int YearsOfService;
    double PayRate;
};


void Display(Employee employee)//Input parameter----- What type ??// do calculation
{
    std::cout << employee.Name << std::endl;
    std::cout << employee.Id << std::endl;
    std::cout << "Year of service" << employee.YearsOfService << std::endl;
    std::cout << "Pay rate" << employee.PayRate << std::endl;

    employee.YearsOfService *= 2;
};

void GivePayRaise(Employee& employee)
{
    //If years >3, payrate + $5
    //If years >5, payrate + $10
    if (employee.YearsOfService > 3)
        employee.PayRate += 5;
    else if(employee.YearsOfService > 5)
        employee.PayRate += 10;
}
int main()
{
    /*int value = ReadInt("Enter a value between 1 to 10: ", 1, 10);

    int positive = ReadInt("Enter a positive number: ", 0);

    int anyValue = ReadInt("Enter a number: ");

    int test = ReadInt("a message", 10, 50);*/

    Employee employee;
    employee.Id = 10;
    employee.Name = "Bob";
    employee.YearsOfService = 10;
    employee.PayRate = 20.5;
    
    Display(employee);
    GivePayRaise(employee);
    Display(employee);
}
