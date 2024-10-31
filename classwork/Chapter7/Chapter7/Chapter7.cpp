
#include <iostream>
#include <string>
#include <iomanip>

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    Point topLeft;
    Point bottomRight;
};

void Display(Point point)
{
    std::cout << "(" << point.x << "," << point.y << ")";
}

void Display(Rectangle rect)
{
    //std::cout << "(" << rect.topLeft.x << "," << rect.topLeft.y << ")";
    std::cout << "(";
    Display(rect.topLeft);
    std::cout << " ";
    Display(rect.bottomRight);
    std::cout << "(";
};

void Translate(Rectangle& rect, int offsetX, int offsetY)
{
    rect.topLeft.x += offsetX;
    rect.bottomRight.x += offsetX;

    rect.topLeft.y += offsetY;
    rect.bottomRight.y += offsetY;
}

//int main()
//{
//    Rectangle rc;
//    rc.topLeft.x = 10;
//    rc.topLeft.y = 20;
//
//    rc.bottomRight.x = 100;
//    rc.bottomRight.y = 75;
//    Display(rc);
//
//    Translate(rc, 5, 10);
//    Display(rc);
//}

void GradeArrayDemo()
{
    const int MaxGrades = 20;
    double dummyValue2 = -1;
    int grades[MaxGrades];
    double dummyValue = 0;

    int estimatedMaxArraySize = sizeof(grades) / sizeof(int); // Size of array/ size of element


    int count = 0;
    for (int index = 0; index < MaxGrades; ++index) // ++count)// Careful about <= should not have
    {
        std::cout << "Enter a grade: ";
        std::cin >> grades[index];
        //grades[index] = 100;

        if (grades[index] <= 0)
            break;
        ++count;
    };
    //for (int index = 0; index < MaxGrades; ++index) for entire array
        for (int index = 0; index < count; ++index)
    {
        std::cout << grades[index] << std::endl;
     }
 
    int indexToChange;
    do 
    {
        std::cout << "Enter the index of the grade to change: ";
        std::cin >> indexToChange;
    } while (indexToChange < 0 || indexToChange >= MaxGrades);
    

    int newGrade;
    std::cout << "Enter the new the grade: ";
    std::cin >> newGrade;

    grades[indexToChange] = newGrade;

}
void InitArrayDemo()
{
    const int Maxrates = 100;
    double payRates[Maxrates] = {0};//Zero initialize

    ///Zero Init
    //for (init index = 0; index < MaxRates; ++index)
    //    payRates[index] = 0;


    //Init days of month
   // char name[] = "Bob";
    std::string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    //monthNames[0] = "Jan";
    //monthNames[1] = "Feb";
    //monthNames[2] = "March";
    //monthNames[3] = "April";

    // zERO EXTEND INITILAIZE ALL ELEMENTS
    
    //int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31 };

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
    
    //daysInMonth[0] = daysInMonth[2] = daysInMonth[4] = daysInMonth[6] = daysInMonth[7] = daysInMonth[9] = daysInMonth[11] = 31;
    //daysInMonth[1] = 28;
    //daysInMonth[3] = daysInMonth[5] = daysInMonth[8] = daysInMonth[12] = 30;

    for (int index = 0; index < 12; ++index)
        std::cout << monthNames[index] << " has " << daysInMonth[index] << "days" << std::endl;
}

//use array condition
void useArrayDemo()
{
    int array1[20] = {0};

    //for (int index = 0; index < 20; ++index)
    //    array1[index] = index + 1;
    //--- modify to pass by parameter alternatively above stick with the above when you modify the index
    for (int& value : array1)
        value = 1;


    //int index2 = 0;
    //while (index2 < 20)
    //{
    //    //array1[index2] = ++index2;      ------- alternatevely down
    //    array1[index2++] = index2 + 1;
    //    //array1[index2] = index2 + 1;
    //    //++index2;
    //}
    
    // for loop for iterating arrays

    //--------------------------------
    //for (int index = 0; index < 20; ++index)
    //   std:: cout << array1[index] << std::endl;
   
    //-----------equivalent below

    // Don't care about to index
    for (int value : array1)
        std::cout << value << std::endl;

}

int main()
{
   
    InitArrayDemo();
    
    
    //double gradeAverages[100];
   // GradeArrayDemo();
}

//this function is not affectinf below the main function
void NameArrayDemo()
{
    //Array is a set of related data
    /*std::string student1;
    std::string student2;
    std::string student3;
    std::string student4;
    std::string student5;*/
    const int MaxStudents = 100;//solve the maintenence issue of array size
    std::string students[MaxStudents];


    //All elememnt are exact same type
 /*   int grades[10];
    grades[0] = 10;
    grades[1] = (short)10;*/

    //store roster of students
    //when using for loop use = 0 to < N
    for (int index = 0; index < MaxStudents; ++index)
    {
        std::string student;
        std::cout << "Enter student Name: ";
        getline(std::cin, student);
        if (student == "")
            break;
        //student at index 0, first element
        //students sub 0
        // Array access operator
        students[index] = student;
    };

    //print roster
    //std::cout << student << endl;
    for (int index = 0; index < MaxStudents; ++index)
    {
        if (students[index] != "")
            std::cout << students[index] << std::endl;
    };
}


