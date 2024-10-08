

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //Display Program Title, My Name, Course and Semester
    cout << " Program title:Lab 2 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << endl;
    //Entering and checking the validation of loan amount
    cout << "Please enter the loan amount: ";
    double loanBalance;
    do
    {
        cin >> loanBalance;
        if (loanBalance < 1 || loanBalance > 1000)
            cout << "Sorry, This loan amount is out of range.";
    }
    while (loanBalance < 1 || loanBalance > 1000);
    cout << endl;
     //Entering and checking the validation of Interest Rate
    double interestRate;
    cout << "Please enter the interest rate (%): ";
    do {
        cin >> interestRate;
        if (interestRate < 1.00 || interestRate >100.00) 
        {
            cout << "You entered the invalid interest rate.";
           
        }
    } while (interestRate < 1.00 || interestRate > 100.00);
    cout << endl;
    //Validation of Payment
    double payAmount;
    do {
        cout << "How much do you want to pay each month? ";
        cin >> payAmount;
        if (payAmount < 0 || payAmount >loanBalance) 
        {
            cout << "That is an invalid value. ";
        }
    } while (payAmount < 0 || payAmount >loanBalance);
    // Table with the Initial Loan Balance
    int month = 1;
    cout << left << setw(7) << "Month " << setw(14) << "   Balance " << setw(12) << "  Payment " << setw(5) << "   Interest" << setw(15) << "     New Balance " << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(10) << month << "$  " << setw(10) << loanBalance << "$  " << setw(10) << "0.00" << "$  " << setw(10) << "0.00" << "$  " << setw(10) << loanBalance << endl;
    // Calculate and display monthly details
    double interest, newLoanBalance;

    double totalPayment = 0.00, higherPayAmount = 0.00, lowerPayAmount = 0.00, lowestPayAmount = 0.00;
    double  totalInterest, interestFirstCase = 0.00, interestSecondCase =0.00, interestThirdCase = 0.00;
    for (int month = 1; month < 12; ++month)
    {
        //calculation of Interest and New Loan Balance After Each Successful Payment
        newLoanBalance = loanBalance - payAmount;
        interest = (newLoanBalance * (interestRate / 100));
        newLoanBalance += interest;
        if (loanBalance >= 20)
        {
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << loanBalance << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newLoanBalance << endl;
            higherPayAmount += payAmount;
            interestFirstCase += interest;
        }
        else if (loanBalance < 20 && loanBalance >= 1)
        {
           lowerPayAmount = loanBalance;
           interestSecondCase += abs(interest * 0);
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << loanBalance << "$  " << setw(10) << lowerPayAmount << "$  " << setw(10) << interestSecondCase << "$  " << setw(10) << abs(newLoanBalance * 0) << endl;
        } 
        else
        {
            double interestThirdCase = abs(interest * 0);
            lowestPayAmount = abs(payAmount * 0);
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << abs(loanBalance*0) << "$  " << setw(10) << lowestPayAmount << "$  " << setw(10) << interestThirdCase << "$  " << setw(10) << abs(newLoanBalance) * 0 << endl;
        }
        loanBalance = newLoanBalance;
    }
    month++;
    //Result for Total Payment and Total Interest
     totalPayment = higherPayAmount + lowerPayAmount + lowestPayAmount;
     totalInterest = interestFirstCase + interestSecondCase + interestThirdCase;
     cout << setw(23) <<"Total" << "$ " << setw(11) << totalPayment << setw(3) << "$ " << totalInterest << "\n";
            
     return 0;
};


 

     
     
     
     
     
 