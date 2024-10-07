

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

    for (int month = 1; month < 12; ++month)
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
           // interest = 0;
            //bal = newBalance;
           // payAmount = bal;

            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << bal << "$  " << setw(10) << abs(interest * 0) << "$  " << setw(10) << abs(newBalance * 0) << endl;
            //bal = newBalance;
            //newBalance = 0;
        } else
        {
           // bal = 0; 
          // payAmount = bal;
            //payAmount = 0,
            //interest = 0;
            cout << fixed << setprecision(2);
            cout << setw(10) << month + 1 << "$  " << setw(10) << abs(bal*0) << "$  " << setw(10) << abs(payAmount*0) << "$  " << setw(10) << abs(interest*0) << "$  " << setw(10) << abs(newBalance) * 0 << endl;
           // bal = newBalance;

        }
        bal = newBalance;

              // bal = newBalance;
                //cout << fixed << setprecision(2);
                //cout << setw(10) << month + 1 << "$  " << setw(10) << bal << "$  " << setw(10) << payAmount << "$  " << setw(10) << interest << "$  " << setw(10) << newBalance << endl;
               // bal = newBalance;
    }

            month++;
     double totalPayment = 0.00, totalInterest=0.00;
     for (int i = 0; i < month; ++i)
     {
 
     
         totalPayment += payAmount;//totalpayment = totalpayment + payAmount
         totalInterest += abs(interest);
        
      } 
      cout << "Total                  $ " << std::setw(6) << totalPayment
                    << "       $ " << std::setw(6) << totalInterest << "\n";
            
    return 0;
};




     
     
     
     
     
 