
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

int main()
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
    for (int index =0; index < MaxStudents; ++index)
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
        if(students[index] != "")
        std::cout << students[index] << std::endl;
    };

}
