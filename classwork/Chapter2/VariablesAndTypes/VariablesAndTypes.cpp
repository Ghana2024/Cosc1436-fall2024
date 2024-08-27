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
    int length;
    length = 0; // assignment statement

    int releaseYear = 1990;// initialzer declaration

    int rating = 3, stars = 5;
    
    std::cout << length;
}   
