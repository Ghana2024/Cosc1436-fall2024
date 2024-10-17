/*
 * COSC 1436
 * Lab 2 Sample
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    /////////////////////////////
    //Program information
    cout << "Lab 2 Sample" << endl;
    cout << "COSC 1436" << endl << endl;

    ////////////////////////////
    //Get the loan amount
    double loanAmount;

    do
    {
        cout << "Please enter the initial loan amount ($1 - $1,000): ";
        cin >> loanAmount;

        if (loanAmount >= 1 && loanAmount <= 1000)
            break;

        cout << "ERROR: Enter a value in the range $1 - $1,000" << endl;
    } while (true);

    /////////////////////////////
    //Get the interest rate
    double interestRate;

    do
    {
        cout << "Please enter the interest (1 - 100 %): ";
        cin >> interestRate;

        if (interestRate >= 1 && interestRate <= 100)
            break;

        cout << "ERROR: Enter a value in the range 1 - 100" << endl;
    } while (true);

    //Adjust the interest rate from percentage to a value we can use
    interestRate /= 100;

    /////////////////////////////
    //Get the payment amount
    double paymentAmount;

    do
    {
        cout << "Please enter the monthly payment amount ($0 - $" << loanAmount << "): ";
        cin >> paymentAmount;

        if (paymentAmount >= 0 && paymentAmount <= loanAmount)
            break;

        cout << "ERROR: Enter a value in the range $0 - $" << loanAmount << endl;
    } while (true);

    ///////////////////////////////////////////////////
    //Display the loan information for the first year
    cout << fixed << setprecision(2) << left;
    cout << endl;
    cout << setw(8) << "Month" << setw(15) << "Balance" << setw(15) << "Payment" << setw(15) << "Interest" << setw(15) << "New Balance" << endl;
    cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;        

    double currentBalance = loanAmount;
    double totalInterest = 0;
    double totalPayments = 0;

    for (int month = 0; month < 12; ++month)
    {
        //Cannot pay more than balance
        if (currentBalance < paymentAmount)
            paymentAmount = currentBalance;

        // Balance for month is current balance - payment
        // Interest is calculated based upon monthly balance
        // New balance is the current balance plus interest
        double newBalance = (month > 0) ? (currentBalance - paymentAmount) : currentBalance;
        double currentInterest = (month > 0 && newBalance > 0) ? newBalance * interestRate : 0;
        newBalance += currentInterest;

        totalPayments += (month > 0) ? paymentAmount : 0;
        totalInterest += currentInterest;

        //Ensure loan doesn't go negative
        if (newBalance < 0)
            newBalance = 0;            

        cout << setw(8) << (month + 1)
             << "$ " << setw(13) << currentBalance
             << "$ " << setw(13) << ((month > 0) ? paymentAmount : 0)
             << "$ " << setw(13) << currentInterest
             << "$ " << setw(13) << newBalance 
             << endl;

        //Update the balance for next month
        currentBalance = newBalance;
    };

    //Show final totals
    cout << setw(8) << "Total"
         << setw(15) << ""
         << "$ " << setw(13) << totalPayments
         << "$ " << setw(13) << totalInterest
         << endl;
}