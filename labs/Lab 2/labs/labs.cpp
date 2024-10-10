

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    //Display Program Title, My Name, Course and Semester
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << " Program title:Lab 2 \n";
    cout << " Ghana Dahal \n";
    cout << " COSC 1436 Fall 2024 \n";
    cout << setw(25) << setfill('*') << "" << setfill(' ') << endl;
    cout << endl;
    //Entering and checking the validation of loan amount
    cout << "Please enter the loan amount between $1 to $1000: ";
    double loanBalance;
    do
    {
        cin >>loanBalance;
        if (loanBalance < 1.00 || loanBalance > 1000.00)
            cout << "Sorry, This loan amount is out of range.Enter the correct amount: ";
    }
    while (loanBalance < 1.00 || loanBalance > 1000.00);
    cout << endl;
     //Entering and checking the validation of Interest Rate
    float interestRate;
    cout << "Please enter the interest rate (%) between 1.0 % to 100.0%: ";
    do {
        cin >> interestRate;
        if (interestRate < 1.00 || interestRate >100.00) 
        {
            cout << "You entered out of range interest rate. Re-enter the correct percentage: ";   
        }
    } while (interestRate < 1.00 || interestRate > 100.00);
    cout << endl;
    //Validation of Payment
    double payAmount;
    do {
        cout << "How much do you want to pay each month? ";
        cin >> payAmount;
        //checking payment fall under range
        if (payAmount < 0 || payAmount > loanBalance)
        {
            cout << setw(15) << setfill('-') << "" << setfill(' ') << "ALERT!!, LESS THAN OR EXCEED RANGE CONDITION." << setw(15) << setfill('-') << "" << setfill(' ') << endl;
            cout << "You have entered amount less than $0 or You have exceed the loan limit. \n";
            cout << "Please provide the correct amount, you want to pay each month. ";
            cout << endl;
        }
    } while (payAmount < 0 || payAmount >loanBalance);
    cout << endl;
    // Table with the Initial Loan Balance
    int month = 1;
    cout << left << setw(7) << "Month " << setw(14) << "   Balance " << setw(12) << "  Payment " << setw(5) << "   Interest" << setw(15) << "     New Balance " << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(10) << month << "$  " << setw(10) <<fixed << setprecision(2) << loanBalance << "$  " << setw(10) << "0.00" << "$  " << setw(10) << "0.00" << "$  " << setw(10) << loanBalance << endl;
    // Calculation and display monthly details
    double interest, newLoanBalance;
    double totalPayment = 0.00, higherPayAmount = 0.00, lowerPayAmount = 0.00, lowestPayAmount = 0.00;
    float  totalInterest, interestFirstCase = 0.00, interestSecondCase =0.00, interestThirdCase = 0.00;
    for (int month = 1; month < 12; ++month)
    {
        //calculation of Interest and New Loan Balance After Each Successful Payment
        newLoanBalance = loanBalance - payAmount;
        interest = (newLoanBalance * (interestRate / 100));
        newLoanBalance += interest;
         if(loanBalance > payAmount)
        {
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << loanBalance << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newLoanBalance << endl;
            higherPayAmount += payAmount;
            interestFirstCase += interest;
        }
        else if(loanBalance < payAmount && loanBalance > 0)
        {
            lowerPayAmount = loanBalance;
            interestSecondCase += abs(interest * 0);
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << loanBalance << "$  " << setw(10) << lowerPayAmount << "$  " << setw(10) << interestSecondCase << "$  " << setw(10) << abs(newLoanBalance * 0) << endl;
        } 
        else
        {
            float interestThirdCase = abs(interest * 0);
            lowestPayAmount = abs(payAmount * 0);
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << abs(loanBalance*0) << "$  " << setw(10) << lowestPayAmount << "$  " << setw(10) << interestThirdCase << "$  " << setw(10) << abs(newLoanBalance) * 0 << endl;
        }
        loanBalance = newLoanBalance;
    }
    month++;
    //Result for Total Payment and Total Interest
    cout << setw(60) << setfill('=') << "" << setfill(' ') << endl;
     totalPayment = higherPayAmount + lowerPayAmount + lowestPayAmount;
     totalInterest = interestFirstCase + interestSecondCase + interestThirdCase;
     cout << setw(23) <<"Total" << "$ " << setw(11) << totalPayment << setw(3) << "$ " << totalInterest << "\n";        
     return 0;
};


 

     
     
     
     
     
 