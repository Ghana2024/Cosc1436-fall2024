#include <iostream>
// header inject the function
int main()// entry point for the program which start with main
{
    // only one function
    // Output a message -1
    // std::endl for new line
    std::cout << "Hello World" << std::endl;
    //syntax c++ << sign are operator and enter the value so the cout is display which stream out 
    //message -2
    std::cout << "Hello" << " " << "World" << std::endl;
    //message -3
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World" << std::endl;

    //Message -4
    std::cout << "Hello\tWorld\n";
    std::cout << "Hello \"Bob\"";

    //File paths
    std::cout << "C:\\windows\\temp";
    //std::cout << R"C:\windows\temp";
    
   //variables-named memory location to store data.

    //Decalration -tell complier a variable exists
    // Scope - lifetime of a variable/identifire: point of declaration to end of block
    //Expression - can be used anywhere an expression is allowed
    //Styling - Name: nouns, Casing :Camel
    int length;
    length = 0; // assignment statement

    int releaseYear = 1990;// initialzer declaration
    int rating = 3, stars = 5;

    
    std::cout << length;
      //identifiers
    //int _hours, _1stGrade, no 1stGrade, no first-grade;
    int examGrade, hoursWorked;
    //std::cout << examgrade
    //int exam_grade, hours_worked; Donot Do this

    // Types
    //Defines what kind of data is stored, range, size
    //primitives - understood by language
    //|type | size | Range
    // 
    //|short | 2 | +-32767 (integral)|
    //| int | 4 | +- 2 billion (default)|
    //| long | 4 | +- 2 billion|
    //|unsgned * | * | 0-
    //


    short s;
    int i = 0;
    long l = 5L;
    unsigned int ui = 3U;

    //Float | 4 | E+-38 | precision: 5-7 |
    //double | 8 | E+- 308 | precision: 12-15 (default) |

    double pi = 3.14159F;
    double largeNumber = 10E100;
    //Text
    //| char | 1 | -128 to 127 |character
    //| std:: string | * | text |
    //| bool | 1? | true or false |
    char c = 'A';
    std::string name = "Bob";
    bool isPassing = true;
    // int isOK = 1; //Don't do it
    int intSize = sizeof(int);// not for quiz

    //Assignment
    // asp_op:: = V = E
    //Must be type compitable

    //rvalue expression is assign side right side
    // lvalue= left side of assign 

    // Expression of type Vt
    // Associativity - Right
    int shapeLength = 10;
    int shapeWidth = 20;
    int shapeArea;

    shapeArea = shapeLength;
    shapeWidth = 10;
    //20 = shapeWidth;
    shapeArea = shapeLength = shapeWidth = 20;

    //Arthematic Operators
    // + - * / % (int modulus)
    // arith_op :: =Et op Et
    shapeArea = shapeLength * shapeWidth;
    int remainder = 10 % 3; // 1
    int result = 10 / 3; // 3
    double dresult = 10.0 / 3.0;//3.333
    // unary_op ::= + Et \ -Et
    int positiveValue = 10;
    int negativeValue = -positiveValue;

    //scope 
    //blockStatement :: = {S*}
    {
        int newVariable = 10;

    }
   // std::cout << newVariable;


} 
 
