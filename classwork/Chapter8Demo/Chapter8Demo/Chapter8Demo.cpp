#include <iostream>
#include <iomanip>
#include <string>


void StackDemo()
{
    double localDouble = 45.6;
    //Declare a pointer to a double
    //Pointer is always a memory address
    // Pointer is always either 4 or 8 bytes long
    // Pointer value is always an integeral value

    // Pointers have 2 data points: integral value ( memeory addresses), value they reference (in memory)
    //address-of :: & variable
    // Type of expression is T* where T is the type of the variable
    double* ptrDouble = &localDouble;; // pointer to double // local variable stored in stack

    //Assign new value to value at memory address

    //Type coercoin doen't bahave the same with pointers
    int localInt = 56;
    localDouble = localInt;
   // ptrDouble = &localInt; not allowed

    //double* !=double
    //ptrDouble = 90.6;


    *ptrDouble = 89.7;
    //Derefeencibg a pointer
    // derefrencine-op :: *expr
    //Type of expression is T where E is T*
    std::cout << ptrDouble << " " << *ptrDouble << std::endl;
    std::cout << (*ptrDouble == localDouble) << std::endl;
};

void EmptyDemo()
{
    float payRate = 12.50;

    // Always Initialize// there are two ways
     
    //float* pPayRate = NULL; // C, old school, not recommended
    //a) NULL is 0
    //b) Always init to 0 or valid memory
    float* pPayRate = nullptr; // C++ recommended


    // Print value and deferenced value
    std::cout << pPayRate << " = " << *pPayRate << std::endl;

    //Always verify pointer before deferencing
    //if(pPayRate != nullptr)
    //std::cout << pPayRate << " = " << *pPayRate;
    //std::cout << std::endl;

   // shortcut of above
    if (pPayRate)
    std::cout << *pPayRate;
    std::cout << std::endl;

    // when deference to the Zero Immediately crashes // access voilentation // somebody drefernec bad address
}

struct Employee
{
    int Id;
    std::string Name;

    int DummyValues[1000];
};

void DynamicMemoryDemo()
{
    const int MaxEmployees = 100;
    Employee* employees[MaxEmployees] = {0};
    int id = 1000;

    //int count = 0;

    //int numberOfEmployees = 0;
    for (int index = 0; index < MaxEmployees; ++index)
    {
       // int id;
        std::string name;
        std::cout << "Enter ID or 0 to quit: ";
        std::getline(std::cin, name);

        if (name == "")
            break;
        // Add to Array
        //new-op :: new T; returns
        Employee* employee = new Employee;
        //(*employee).Id = ++id;
        employee->Id = ++id;
        employee->Name = name;
        employees[index] = employee;
        //++numberOfEmployees;

    }
    //print employyes
    for (int index = 0; index < MaxEmployees; ++index)
    {
        //If done text 
        if (employees[index] == nullptr)
            break;
        std::cout << "[" << employees[index]->Id << "]" << employees[index]->Name << std::endl; // dynamic pointer 
    };

//Ensure that any memory allocated by new is cleaned up using delete;
//delete - op :: = delete E;
    for (int index = 0; index < MaxEmployees; ++index)
    {
        if (employees[index] == nullptr)
            break;
        //Delete Memory
        Employee* employee = employees[index];
        delete employee;
        employees[index] = nullptr; //Always reset to null avoid issues
        delete employees[index];
       // employee->Id = 20; //Going to fail

        //delete &index; //Bad things will happen
    };
}

int main()
{
    //StackDemo();
    //EmptyDemo();
    while (true)
    { }
    DynamicMemoryDemo();
    //char choice;
   // std::cout << "Keep going(Y / N)?";
    //std::cin >> choice;
    //if ( choice == N || choice == n)
    //   break;
        
}

