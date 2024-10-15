//

#include <iostream>

    // Function definition
    void greet(std::string name)
    {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
    //call stack
    void functionA() {
        std::cout << "Inside functionA" << std::endl;
    }

    void functionB() {
        std::cout << "Inside functionB" << std::endl;
        functionA();
    }
       // Function prototype
    void greet(std::string name);

    int main() 
 {
        greet("Alice"); // Calling the function with an argument
        std::cout << "Inside main" << std::endl;//using callstack 
        functionB();
        return 0;
}

