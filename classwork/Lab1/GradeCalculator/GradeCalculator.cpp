// GradeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Program title: Lab1
//Ghana Dahal
// COSC 1436 Fall 2024

#include <iostream>

int main()
{
    //Prompt the user for their name and grades.
    //Enter the user name
    std::string uname;
    std::cout << "Please enter your name: " << std::endl;
    std::cin >> uname;
    //Entering their lab grade
    int fLab, sLab, tLab, ftLab;
    std::cout << "Enter all grades 0 to 100 only" << std::endl;
    std::cout << "Please enter lab 1: ";
    std::cin >> fLab;
    std::cout << "Please enter lab 2: ";
    std::cin >> sLab;
    std::cout << "Please enter lab 3: ";
    std::cin >> tLab;
    std::cout << "Please enter lab 4: ";
    std::cin >> ftLab;
    //Entering their exam grade
    int fExam, sExam, tExam;
    std::cout << "Please enter exam 1: ";
    std::cin >> fExam;
    std::cout << "Please enter exam 2: ";
    std::cin >> sExam;
    std::cout << "Please enter exam 3: ";
    std::cin >> tExam;

    //Entering their participation and final exam grade
    int par, final;
    std::cout << "Please enter participation: ";
    std::cin >> par;
    std::cout << "Please enter final exam: ";
    std::cin >> final;

    //Display the User lab Result
    std::cout << uname << ", your lab grades are:" << std::endl;
    std::cout << "Lab 1" << "= " << fLab << std::endl;
    std::cout << "Lab 2" << "= " << sLab << std::endl;
    std::cout << "Lab 3" << "= " << tLab << std::endl;
    std::cout << "Lab 4" << "= " << ftLab << std::endl;

    //Display the User exam Result
    std::cout << uname << ", your exam grades are:" << std::endl;
    std::cout << "Exam 1" << "= " << fExam << std::endl;
    std::cout << "Exam 2" << "= " << sExam << std::endl;
    std::cout << "Exam 3" << "= " << tExam << std::endl;

    //Display the user other grade
    std::cout << uname << ", your exam other grades are:" << std::endl;
    std::cout << "Participation" << "= " << par << std::endl;
    std::cout << "Final Exam" << "= " << final << std::endl;




}
