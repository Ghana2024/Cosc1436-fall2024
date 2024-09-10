#include <iostream>
// header inject the function
//Declares a point as an X and Y value
struct Point
{
    //Declares variables -fields
    //variables inside decl are called fields
    int X;
    int Y;

};//For long time complier work
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

    //sring stuff
    //Not a primitive
    //Does not work outside C++
    std::string message = "Hello";
    message = message + " World";//concatenate the strings
    message = message + " " + name;

    std::string empty;
    empty = empty + "Hello";

    //combination OPerators
    // V op = E
    empty += " World"; //empty = empty + " World";

    // C++ is strongly typed
    int number = 10;

    //Type inferencing (C++11)
    //auto ::= complier figures it out
    //Only usable in variable decls and a few other places
    // Must use an init expression when declariing the variable

    auto payRate = 45.6;
    //payRate = "45.6";
    double averagePayRate = 40 / payRate;

    //Area of a circle =PI*R2
   // const double pi = 3.14159;
    double radius = 10;

    // constant expression = expression that is calculated at comple time, primitive
    //4+5 * 8 = 44
    //Literrals are great unless you need them everywhere (constant-expression)
    //Varibles are better at reuse but may be accidently changed
    //Const (Constant expression) with name , type and value and read only, primitives
    double area = 3.14159 * radius * radius;
    area = pi * radius * radius;
    //pi =10; //Error


    // Structure - a group of related data points
    // Cannot use structs with cout
    //Prompt user for a point
  
    // int x, y;
    //Point pt;
    Point pt = {0}; // Zero initializes fields //pt.X = 0; pt.Y = 0;
    std::cout << "Enter X value: ";
    pt.X = 5;
    std::cout << "Enter Y value: ";
    pt.Y = 10;

    //(5, 10)
    std::cout << "(" << pt.X << "' " << pt.Y << ")";

    //Struct assignment is value assignment, all filds are copied
    Point pt2 = pt;

}
    


 
 
