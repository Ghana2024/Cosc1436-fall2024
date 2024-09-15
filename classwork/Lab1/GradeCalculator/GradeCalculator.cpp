// GradeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Program title:Lab1
//Ghana Dahal
// COSC 1436 Fall 2024

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    //Prompt the user for their name and grades.
    //Enter the user name
    std::string uname;
    std::cout << "Please enter your name: ";
    std::cin >> uname;
    std::cout << std::endl;
   
    //Entering their lab grade
    int fLab, sLab, tLab, fthLab;
    std::cout << "Enter all grades 0 to 100 only" << std::endl;
    std::cout << "Please enter lab 1: ";
    std::cin >> fLab;
    std::cout << "Please enter lab 2: ";
    std::cin >> sLab;
    std::cout << "Please enter lab 3: ";
    std::cin >> tLab;
    std::cout << "Please enter lab 4: ";
    std::cin >> fthLab;
    std::cout << std::endl;
   
    //Entering their exam grade
    int fExam, sExam, tExam;
    std::cout << "Please enter exam 1: ";
    std::cin >> fExam;
    std::cout << "Please enter exam 2: ";
    std::cin >> sExam;
    std::cout << "Please enter exam 3: ";
    std::cin >> tExam;
    std::cout << std::endl;

    //Entering their participation and final exam grade
    int part, final;
    std::cout << "Please enter participation: ";
    std::cin >> part;
    std::cout << "Please enter final exam: ";
    std::cin >> final;
    std::cout << std::endl;

    //Display the User lab Result
    std::cout << uname << ", your lab grades are:" << std::endl;
    std::cout << "Lab 1" << " = " << fLab << std::endl;
    std::cout << "Lab 2" << " = " << sLab << std::endl;
    std::cout << "Lab 3" << " = " << tLab << std::endl;
    std::cout << "Lab 4" << " = " << fthLab << std::endl;
    std::cout << std::endl;

    //Display the User exam Result
    std::cout << uname << ", your exam grades are:" << std::endl;
    std::cout << "Exam 1" << " = " << fExam << std::endl;
    std::cout << "Exam 2" << " = " << sExam << std::endl;
    std::cout << "Exam 3" << " = " << tExam << std::endl;
    std::cout << std::endl;

    //Display the user other grade
    std::cout << uname << ", your exam other grades are:" << std::endl;
    std::cout << "Participation" << " = " << part << std::endl;
    std::cout << "Final Exam" << " = " << final << std::endl;
    std::cout << std::endl;

    //Display the user name with lab and exam averages with 2 decimal place
    double avgLab, avgExam;
    avgLab = (fLab + sLab + tLab + fthLab) / 4.0;
    avgExam = (fExam + sExam + tExam) / 3.0;

    //Adjust the Average Class Calculation based on percentage of each grade
    double avgPercentLab, avgPercentExam, percentParticipation, percentFinal;
    avgPercentLab = avgLab * (65.0 / 100);
    avgPercentExam = avgExam * (20.0 / 100);
    percentParticipation = part * (5.0 / 100);
    percentFinal = avgLab * (10.0 / 100);

    //Calculation of Class Average
    double avgClass = avgPercentLab + avgPercentExam + percentParticipation + percentFinal;

  
    // Display all the final result 
    std::cout << uname << ", your exam other grades are:" << std::endl;
    std::cout << "Lab Average (65%) " << "= " << std::fixed << std:: setprecision(2) << avgLab << "%" << std::endl;
    std::cout << "Exam Average (20%) " << "= " << std:: setprecision(2) << avgExam << "%" << std::endl;
    std::cout << "Participation (5%) " << "= " << part << "%" << std::endl;
    std::cout << "Final Exam (10%) " << "= " << final << "%" << std::endl;
    std::cout << "Class Average " << "= " << std::fixed << std::setprecision(2) << avgClass  << "%" << std::endl;






}



