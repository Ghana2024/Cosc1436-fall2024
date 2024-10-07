

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
 
    cout << "Please enter the loan amount: ";
    double bal;
    cin >> bal;// Initial Balance
    cout << endl;
    double intRate;
    cout << "Please enter the interest rate (%): ";
    do {
        cin >> intRate;
       // cout << "Please enter the interest rate (%): ";
        if (intRate <= 0.00 && intRate >=101.00) 
        {
            cout << "Enter the valid Interest Rate.";
           
        }
    } while (intRate <= 0.00 && intRate >= 101.00);
    cout << endl;
   // double payAmount;
    double payAmount;
    //int month = 1;
    do {
        cout << "How much do you want to pay each month? ";
        cin >> payAmount;
        if (payAmount <= 0) {
            cout << "That is an invalid value. ";
        }
    //int month = 1;

    } while (payAmount <= 0);
   
    int month = 1;
    cout << left << setw(8) << "Month " << setw(10) << "   Balance " << setw(10) << "  Payment " << setw(6) << "   Interest" << setw(12) << "    New Balance " << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    cout << setw(10) << month << "$  " << setw(10) << bal << "$  " << setw(10) << "0.00" << "$  " << setw(10) << "0.00" << "$  " << setw(10) << bal << endl;
    
    // Calculate and display monthly details
    double interest, newBalance;

    for (int index = 1; index < 12; ++index)
    {
        newBalance = bal - payAmount;
        interest = (newBalance * (intRate / 100));
        newBalance += interest;
        if (bal >= 20)
        {
           // = bal - payAmount;
           // = (n==ewBalance * (intRate / 100));
           //newBalance += interest;
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newBalance << endl;
            //bal = newBalance;
        } else if (bal < 20 && bal >= 1)
        {
            interest = 0;
            //bal = newBalance;
            payAmount = bal;

            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << abs(newBalance) * 0 << endl;
            //bal = newBalance;
            //newBalance = 0;
        } else
        {
            bal = 0; 
            newBalance = bal;
            payAmount = 0, interest = 0;
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newBalance << endl;
           // bal = newBalance;

        }
        bal = newBalance;

              // bal = newBalance;
                //cout << fixed << setprecision(2);
                //cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newBalance << endl;
               // bal = newBalance;
    }

            month++;
    double totalPayment = 0.0, totalInterest= 0.0;
    for (int i = 0; i < month; ++i) 
    {
       // double totalPayment = 0.0, totalInterest = 0.0;
        totalPayment += payAmount;//totalpayment = totalpayment + payAmount
        totalInterest += interest;
    }

    cout << "Total                  $ " << std::setw(6) << totalPayment
        << "       $ " << std::setw(6) << totalInterest << "\n";

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



