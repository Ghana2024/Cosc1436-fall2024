// GradeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Program title:Lab1
//Ghana Dahal
// COSC 1436 Fall 2024

#include <iostream>
#include <iomanip>
#include <string>


int main()
{
    std::cout << " Program title:Lab1\n";
    std::cout << " Ghana Dahal \n";
    std::cout << " COSC 1436 Fall 2024 \n";
    std::cout << std::endl;
    //Prompt the user for their name and grades.
    //Enter the user name
    std::string uname;
    std::cout << "Please enter your name: ";
    std:getline(std::cin, uname);
    std::cout << std::endl;
   
    //Entering their lab grade
    int lab1Grade, lab2Grade, lab3Grade, lab4Grade;
    std::cout << "Enter all grades 0 to 100 only" << std::endl;
    std::cout << "Please enter lab 1: ";
    std::cin >> lab1Grade;
    std::cout << "Please enter lab 2: ";
    std::cin >> lab2Grade;
    std::cout << "Please enter lab 3: ";
    std::cin >> lab3Grade;
    std::cout << "Please enter lab 4: ";
    std::cin >> lab4Grade;
    std::cout << std::endl;
   
    //Entering their exam grade
    int exam1Grade, exam2Grade, exam3Grade;
    std::cout << "Please enter exam 1: ";
    std::cin >> exam1Grade;
    std::cout << "Please enter exam 2: ";
    std::cin >> exam2Grade;
    std::cout << "Please enter exam 3: ";
    std::cin >> exam3Grade;
    std::cout << std::endl;

    //Entering their participation and final exam grade
    int participate, final;
    std::cout << "Please enter participation: ";
    std::cin >> participate;
    std::cout << "Please enter final exam: ";
    std::cin >> final;
    std::cout << std::endl;

    //Display the User lab Result
    std::cout << uname << ", your lab grades are:" << std::endl;
    std::cout << "Lab 1" << " = " << lab1Grade << std::endl;
    std::cout << "Lab 2" << " = " << lab2Grade << std::endl;
    std::cout << "Lab 3" << " = " << lab3Grade << std::endl;
    std::cout << "Lab 4" << " = " << lab4Grade << std::endl;
    std::cout << std::endl;

    //Display the User exam Result
    std::cout << uname << ", your exam grades are:" << std::endl;
    std::cout << "Exam 1" << " = " << exam1Grade << std::endl;
    std::cout << "Exam 2" << " = " << exam2Grade << std::endl;
    std::cout << "Exam 3" << " = " << exam3Grade << std::endl;
    std::cout << std::endl;

    //Display the user other grade
    std::cout << uname << ", your exam other grades are:" << std::endl;
    std::cout << "Participation" << " = " << participate << std::endl;
    std::cout << "Final Exam" << " = " << final << std::endl;
    std::cout << std::endl;

    //Display the user name with lab and exam averages with 2 decimal place
    double avgLab, avgExam;
    avgLab = (lab1Grade + lab2Grade + lab3Grade + lab4Grade) / 4.0;
    avgExam = (exam1Grade + exam2Grade + exam3Grade) / 3.0;

    //Adjust the Average Class Calculation based on percentage of each grade
    double avgPercentLab, avgPercentExam, percentParticipation, percentFinal;
    avgPercentLab = avgLab * (65.0 / 100);
    avgPercentExam = avgExam * (20.0 / 100);
    percentParticipation = participate * (5.0 / 100);
    percentFinal = final * (10.0 / 100);

    //Calculation of Class Average
    double avgClass = avgPercentLab + avgPercentExam + percentParticipation + percentFinal;

  
    // Display all the final result 
    std::cout << uname << ", your exam other grades are:" << std::endl;
    std::cout << "Lab Average (65%) " << "= " << std::fixed << std:: setprecision(2) << avgLab << "%" << std::endl;
    std::cout << "Exam Average (20%) " << "= " << std::setprecision(2) << avgExam << "%" << std::endl;
    std::cout << "Participation (5%) " << "= " << participate << "%" << std::endl;
    std::cout << "Final Exam (10%) " << "= " << final << "%" << std::endl;
    std::cout << "Class Average " << "= " << avgClass  << "%" << std::endl;






}



