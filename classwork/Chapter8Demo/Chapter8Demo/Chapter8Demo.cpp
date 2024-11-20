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

//Pointers can be passed as parameters
//void DisplayInt ArrayDemo(int arr[], int size)
void DisplayIntArrayDemo(int* arr, int size)
{
    int values[100];

    for (int index = 0; index < 100; ++index)
        std::cout << arr[index] << " ";
    std::cout << std::endl;

   

}

void ArrayPointerDemo()
{
    int values[100];
    
    //Array variables are pointer
    int* ptrValues = values;

    for (int index = 0; index < 100; ++index)
    {
        //Pointer arthimetric
        // Add/substraction
        // Value is always multiplied by sizeOf(T) so you are referencing a whole element
        //arr[index] = arr = index = arr + (sizeof(T) * index)
        //arr[index] = *(arr + index)---

        *(ptrValues + index) = index + 1;
        //--QUIZ) raise uo equivalent to two lines up
        //*(ptrValues + (sizeof(int) * index)) = index + 1;

    };

    /*for (int index = 0; index < 100; ++index)
        value[index] = index + 1;*/

    DisplayIntArrayDemo(values, 100);

    int localVariable = 100;
    DisplayIntArrayDemo(&localVariable, 1);

}

void NewArrayDemo()
{
    //double arr[100];
    //Dynamically allocate array at run time

    int size;
    std::cout << "hOW MANY ELEMENT: ";
    std::cin >> size;

    //Aray decl won't work at runtime
    //new T[size]
    // Size must be integral and > 0
    //Ensure you delete this when done
    double* arr = new double[size];

    //Arrays and pointer are interchangeable so nothing else change
    for (int index = 0; index < size; ++index)
    {
        std::cout << "Enter a value: ";
        std::cin >> arr[index];

        if (arr[index] == 0)
            break;
    }
    //clean up
    //delete arr; //This is wrong by the way
    delete[] arr; // Required for array to delete properly clean up all the array
}


void NewArrayDemo2()
{
    while (true)
    {
        NewArrayDemo();

        std::cout << "Keep going (Y/N)?";

        char choice;
        std::cin >> choice;

        if (choice == 'N' || choice == 'n')
            break;
    };
};

//Employee is pass by reference, any changes to employee are visible to caller
void InitializeEmployeeByRef(int& employee)
{
    //No need to validate argument

    std::cout << "Enter the employee Id: ";
        //std::getline(std::cin, employee.Name);
    std::cin >> employee;
};

//Employee is pass by value (memory address), any changes to employee are visible to caller
void InitializeEmployeeByPtr(int* employee)
{
    //valiadet 
    if(employee) //employee != nullptr || employee != Null
    {
       // employee++;

        std::cout << "Enter the employee ID: ";
    //std::getline(std::cin, employee.Name);
        std::cin >> *employee;
    }

};

void PassByRefVsPointerDemo()
{
   // Employee employee;
    int employeeId;
    //pass by ref - must pass a variable
    InitializeEmployeeByRef(employeeId);

    //Pass by value -must pass the address of variable
    InitializeEmployeeByPtr(&employeeId);

    //InitializeEmployeeByPtr(null);
}

Employee* CreateEmployee()
{
    Employee* ptrEmployee = new Employee();

    return ptrEmployee;
}

int* FindElement(int value[], int size, int desiredValue)
{
    for (int index = 0; index < size; ++index)
    {
        if (value[index] == desiredValue)
            return &value[index];
    };
    return nullptr;
}

double g_SomeVariable = 9.18175;
double* GetConstant()
{
    return &g_SomeVariable;
}

double* DontDoThis()
{
    double someValue = 1.2914;

   return &someValue;
}

void PointerReturnDemo()
{
    //Pointer as return type
    //New instance from function(caller is responsible for lifetime)
    //RAII- Resource Acquistion is Initialization between caller and 
    Employee* pNewEmployee = new Employee();
    delete pNewEmployee;//first sceniro(pointer to functiuon)

    //Pointer is to memory that the caller
    int values[100] = {0};
    values[50] = 20;
    int* pMatch = FindElement(values, 100, 20);// second ssceniro

    //Pointer to global object
    double* pConstant = GetConstant();// thid sceniro
}

//message is a refrence to a constant string
//reference for pref reasons
//also work --const std::string&
int ReadInt(std::string const& message)
{
    //Constant, cannot modify
    //message = "Broke";
    std::cout << message;
    int value;
    std::cin >> value;
}
void ConstantPointerDemo()
{
    std::string message = "Enter a number: ";
    int value = ReadInt("Enter a number");
   // int value = ReadInt(message);

    //non-const vs const
    int nonconstValue = 10;
    const int constValue = 20;

    //const are read only;
    //constValue = 30;

    int* pNonConst = &nonconstValue;
    *pNonConst = 40;

    //can add const to some thing(non-const to const is allowed)
    // Cannot take away const from something (const to non-const is not allowed)
    //pNonConst = &constValue;
    *pNonConst = 50;
    //non-const to const is allowed
    int const* pConst = &constValue;
    pConst = &nonconstValue;

    nonconstValue = (int)45.6; //c-style
    nonconstValue = static_cast<int>(45.6); //C== cast

    //Const_cast<T> casts T to either const T or T depending on what it is

    pConst = const_cast<int*>(&nonconstValue);
    pNonConst = const_cast<int*>(&constValue);
    *pNonConst = 50;
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
    ArrayPointerDemo();   
        
}

