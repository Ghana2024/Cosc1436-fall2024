// labs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //struct Movie
    //{
    //    //Required
    //    string Title;

    //    // At least 0, minutes
    //    int RunLength;

    //    //Optional
    //    string Description;

    //    // >=1900
    //    int ReleaseYear;

    //    bool IsClassic;
    //};
    cout << "Please enter the loan amount: ";
    double bal;
    cin >> bal;// Initial Balance
    cout << endl;
    cout << "Please enter the interest rate (%): ";
    double intRate;
    cin >> intRate;
    cout << endl;
    double payAmount;
    int month = 1;
   



    do {
        cout << "How much do you want to pay each month? ";
        cin >> payAmount;
        if (payAmount <= 0) {
            cout << "That is an invalid value. ";
        }
    } while (payAmount <= 0);


    cout << left << setw(8) << "Month " << setw(10) << "   Balance " << setw(10) << "  Payment " << setw(6) << "   Interest" << setw(12) << "    New Balance " << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(10) << month << "$  " << setw(10) << bal << "$  " << setw(10) << "0.00" << "$  " << setw(10) << "0.00" << "$  " << setw(10) << bal << endl;

    
    // Calculate and display monthly details
    while (bal > 0 || month <= 12) {
        double interest = (bal * (intRate / 100));
        double principal = payAmount - interest;
        bal -= principal;

        if (bal < 0 && month >2) {
            principal += bal;
            bal = 0;
        }
        cout << fixed << setprecision(2);
       cout << setw(10) << month << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << principal << endl;

        
        month++;
    }

    return 0;
};

     
     
     
     
     
     
  /*
     
     
     for (int month = months + 1; month <= 12 ; ++month)
     {
      
        
            //cout << left << setw(8) << "Month " << setw(10) << "   Balance " << setw(10) << "  Payment " << setw(6) << "   Interest" << setw(12) << "    New Balance " << endl;

             double remainBalance = bal - payAmount;
             double interest = remainBalance * (intRate / 100);
             double newBalance = remainBalance + interest;
             //cout << interest;
             //double paidAmount = payAmount + interest;
             cout << fixed << setprecision(2);
            // double newBalance = false;// bal - paidAmount;

             //while (month <12)
             //{ 
             if (remainBalance < newBalance)
             {

                 cout << setw(10) << month << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newBalance << endl;

             }   
             // remainBalance -= payAmount;
          //}


          //double loanBalance, interestRate;
          // int months;
            // months++;
            // double remainBalance = bal - payAmount;
            // double interest = remainBalance * (intRate / 100);
             //double newBalance = remainBalance + interest;
        

     }
    return 0;

    

}
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//
//using namespace std;
//
//int main()
//{
//
//    double startingBalance = 0.0;
//    double interestRate = 0.0;
//    double monthlyPayment = 0.0;
//    double monthlyBalance = 0.0;
//    double compountInterest = 0.0;
//    double balance = 0.0;
//    int month = 0;
//
//    cout << fixed << showpoint;
//    cout << setprecision(2);
//
//    cout << "Starting loan balance: ";
//    cin >> startingBalance;  //User input starting loan balance
//    if (startingBalance <= 0) {
//        cout << "\nPlease enter a positive number: ";
//        cin >> startingBalance;
//    }
//    cout << "\nAnnual interest rate: ";
//    cin >> interestRate;  //User input interest rate
//    if ((interestRate <= 0) || (interestRate > 1)) {
//        cout << "\nPlease enter an interest rate ranging from 0 to 1: ";
//        cin >> interestRate;
//    }
//    cout << "\nMonthly payment: ";
//    cin >> monthlyPayment; //User input monthly payment
//    if (monthlyPayment <= 0) {
//        cout << "\nPlease enter a positive number: ";
//        cin >> interestRate;
//    }
//
//    startingBalance = balance;
//
//    cout << "\nMonth \t Balance\n" << endl; //Outputs a schedule of payments
//
//    while ((balance > 0) || (month < 61))
//    {
//        balance += (startingBalance * (interestRate / 12));
//        balance -= monthlyPayment;
//
//        month = month++;
//
//        cout << month << "\t" << balance << "\n";
//
//    }
//
//
//
//    return 0;
*/



