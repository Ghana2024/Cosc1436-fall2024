#include <iostream>
#include <string>
#include <cmath>//c math function
#include <iomanip>

//Include the std namespace so we 
using namespace std;

int main()
{
   //Get user's name
//    std::string name;
//    std::cout << "Enter your name: ";
//
//    //std::cin >> V
//    //Inserts value up to first whitespace into variable
//    // Doesn't work with spaced strings
//    //std::cin name
//    std::getline(std::cin, name);
//  
//
//    std::cout << "Hello " << name << std::endl;
//
//    int hours;
//    std::cout << "How many hours did you work this week? ";
//    std::cin >> hours;
//
//    double payRate;
//    std::cout << "how much do you earn an hour? ";
//    std::cin >> payRate;
//
//    std::cout << "You earned $" << (hours * payRate) << " this week" << std::endl;
//
//   //Multi-value nput , values are whitespace separated
//    int x, y;
//    std::cout << "Enter the x, y values of a point: ";
//    std::cin >> x >> y; 
//
//    //Type Coercion - Compiler changes type of expression
//    //No impact on runtime code genertaion
//    //Always safe
//    // Only impacts current expression
//    // Type hierarchy: larger of two operand types
//    //double
//    //float
//    //unsigned long
//    // long
//    //unsigned int
//    // int 
//    // char/short/unsigned short (automated to int)
//
//    //double =int * double
//    //double= double * double (type coercion)
//    // double = double
//    double result = hours * payRate;
//
//    //precedence rules don't apply, just find the largest type
//    // double + float * int => double
//    
//
//    //Assignment doesn't matter, types determined on each side of operator
//    //double = int * float
//
//    //OVERFLOW AND UNDERFLOW
//    short smallValue = 32767 + 1; //Overflow
//    std::cout << smallValue << std::endl;
//   
//    short largeValue = -32768 - 1; //Underflow
//    std::cout << largeValue << std::endl;
//
//    //float floatValue = 1e38 + 1e2;
//    float floatValue = 1e38 * 2e20;
//    std::cout << floatValue << std::endl;
//
//
//    //New class 09/11/2024
//    //Type Casting
//    //Formatted output
//    //Math
//
//
////TypeCasting - you convert an expression to another type explicitly
//    int totalSales = 50000;
//    int departments = 8;
//
//    //static_cast<T>(E)
//    // Must be allowable
//    //double avergeSalesPerDepartment = static_cast<double>(totalSales) / departments;
//    double averageSalesPerDepartment = totalSales / static_cast<double>(departments);//strongly recommended
//    averageSalesPerDepartment = totalSales / (double)departments;//simple arthematics
//
//    std::string someString = "hello";
//   // int someStringNumber= static_cast<int>(someString);
//    //int someStringNumber = (int)someString; not allowed
//   //use cast to trancated data w/b complier warning
//    int truncatedValue = static_cast<int>(floatValue);
//
//
//    //Math functions
//    //pow(x, y) -> x to the y power
//    //sqrt(x) => square root of x
//    //exp(x) => e to the power
//    //log(x) +> log of x  log(exp(x)) = x
//    //sin(x), cos(x), ..................
//    //abs(x) => positive value of x
//    //ceil(x) => smallest possible int Value >= x
//    //floor(x) => largest possible int value <= x
//    //trunc(x) => rounds towards zero
//    //round(x) => rounds to the nearest interger (midpoint rounding)
//    double xValue = 45.6;
//    double mathResult;
//
//    std::cout << pow(xValue, 2) << std::endl;//xValue * xValue
//    std::cout << sqrt(xValue) << std::endl;
//
//    std::cout << exp(2) << std::endl;//e nth power, e = 2.718
//    std::cout << log(5.4) << std::endl; //root of e
//
//    std::cout << abs(-45) << std::endl; //positive X = 45
//
//    std::cout << ceil(xValue) << std::endl;//46
//    std::cout << floor(xValue) << std::endl;//45
//
//    std::cout << trunc(xValue) << std::endl;//45
//    std::cout << round(xValue) << std::endl;//46
//
//    //Formatted Output
//    std::cout << 4.5679878559 << std::endl;
//    std::cout << 5.67e3 << std::endl;

   // create a table
// Manipulator | behavior | persist
//------------------
// setw(i) | pads the value to i
//left | left justifies | yes
//right | Right justifies (default) | yes
//fixed | Forces fixed point notation | Yes
//setprecision(i) | Sets precision of floats to total digits if fixed and decimal digits if fixed | Yes

    //cout << left << std::setw(8) << "Student " << setw(6) << "Grade " << setw(6) << "Letter " << endl;
    //cout << setw(20) << setfill('-') << "" << setfill(' ') << endl;
    ////cout << fixed;
    //cout << fixed <<setprecision(2);
    //cout << setw(8) << "Bob" << setw(6) << 95.67 << setw(6) << "A" << endl;
    //cout << setw(8) << "Sue" << setw(6) << 98.543 << setw(6) << "A" << endl;
    //cout << setw(8) << "Jim" << setw(6) << 84.567 << setw(6) << "B" << endl;
    //cout << setw(8) << "Jan" << setw(6) << 78.987 << setw(6) << "C" << endl;
   
    //int num;
    //int count = num +1;


    // SELF PRACTICE
    
    cout << "Please enter the loan amount: ";
    double bal; 
    cin >> bal;// Initial Balance
    cout << endl;
    cout << "Please enter the interest rate (%): ";
    double intRate;
    cin >> intRate;
    cout << endl;
    cout << "How much do you want to pay each month? ";
    double payAmount;
    cin >> payAmount;

    /*double interest = bal * (intRate / 100);
    double paidAmount = payAmount + interest;
    double newBalance = bal - paidAmount;*/





    cout << left << setw(8) << "Month " << setw(10) << "   Balance " << setw(10) << "  Payment " << setw(6) << "   Interest" << setw(12) << "    New Balance " << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    //cout << fixed;


    for (int i = 1; i <= 12; ++i)
    {
        //cout << left << setw(8) << "Month " << setw(10) << "   Balance " << setw(10) << "  Payment " << setw(6) << "   Interest" << setw(12) << "    New Balance " << endl;
        //cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
       
        double interest = bal * (intRate / 100);
        double paidAmount = payAmount + interest;
        cout << fixed << setprecision(2);
        cout << setw(10) << i << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << "0.00" << "$  " << setw(10) << bal << endl;
        double newBalance = bal;
        while (newBalance)
        {
        //    //double interest = bal * (intRate / 100);
        //    //double paidAmount = payAmount + interest;
            newBalance = bal - paidAmount;
           // cin >> newBalance;    
            cout << setw(10) << i << "$  " << setw(10) << newBalance << "$  " << setw(10) << payAmount << "$  " << setw(10) << "0.00" << "$  " << setw(10) << newBalance << endl;
        //    //cout << setw(8) << "Sue" << setw(6) << 98.543 << setw(6) << "A" << endl;
        //    //cout << setw(8) << "Jim" << setw(6) << 84.567 << setw(6) << "B" << endl;
        //    //cout << setw(8) << "Jan" << setw(6) << 78.987 << setw(6) << "C" << endl;
          //  newBalance -1;
        };
        break;
    }
    //return 0;

    //double initialValue = 100000; // Initial value
    //double yearlyReductionPercentage = 25; // Yearly reduction percentage
    //int months = 36; // Number of months

    //// Calculate the monthly reduction factor
    //double monthlyReductionFactor = pow(1 - yearlyReductionPercentage / 100, 1.0 / 12);

    //// Calculate the value after each month
    //for (int i = 1; i <= months; ++i) {
    //    initialValue *= monthlyReductionFactor;
    //    std::cout << "Value after month " << i << ": " << initialValue << std::endl;
    //}

    //return 0;
}

