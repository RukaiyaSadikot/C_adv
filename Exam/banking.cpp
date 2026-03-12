#include<iostream>
#include<cstring>
using namespace std;

class Bank
{
    private:
        int accnumber;
        float balance;
        char holdername[50];
    public:
        // Bank(int acno,const char holder[], float bal){
        //     accnumber = acno;
        //     strcpy(holdername, holder);
        //     balance = bal;
        // }
        
        Bank(){
            cout << "Enter account number :";
            cin >> accnumber;
            cin.ignore();
            cout << "Enter Account holder name :";
            cin.getline(holdername, 50);
            cout << "Enter account balance :";
            cin >> balance;
            // cin.ignore(); 
               }
        void credit(float amount){
            balance += amount;
            cout << amount << " amount credited " << endl;
        }

        void debit(float amount){
            if (amount > balance)
            {
                cout << "Insufficient balance to debit the amount" << endl;
            }else{
                balance -= amount;
                cout << amount << " amount debited " << endl;

            }
            
        }

        void display() 
        {
            cout << "Account: " << accnumber << "\t Account Holder: " << holdername << "\t Balance: " << balance << endl;
        }
};

int main(){

    int ch,amt;
    Bank b1;
    do{
        cout << "1. To display your account info " << endl;        
        cout << "2. To Credit amount " << endl;
        cout << "3. To Debit amount " << endl;
        cout << "0. to Exit " << endl;
        cout << "enter your choice " ;
        cin >> ch;

        switch (ch)
        {
            case 1:
                b1.display();
                break;
            case 2:
                cout << "enter amount to credit " ;
                cin >> amt;
                b1.credit(amt);
                break;
            case 3:
                cout << "enter amount to debit " ;
                cin >> amt;
                b1.debit(amt);
                break;
            case 0:
                break;
            default:
                cout << "Invalid Choice";
                break;
            }
    }while(ch != 0);


    return 0;
}


// #include <iostream>
// using namespace std;

// class BankAccount {
// private:
//     int accountNumber;
//     double balance;
//     string ownerName;

// public:
//     BankAccount(int accNo, string owner, double bal) {
//         accountNumber = accNo;
//         ownerName = owner;
//         balance = bal;
//     }

//     void credit(double amount) {
//         balance += amount;
//     }

//     void debit(double amount) {
//         if(amount <= balance) balance -= amount;
//         else cout << "Insufficient balance!" << endl;
//     }

    // void displayBalance() {
    //     cout << "Account: " << accountNumber 
    //          << ", Owner: " << ownerName 
    //          << ", Balance: " << balance << endl;
    // }
// };

// int main() {
//     BankAccount acc1(101, "Rukaiya", 5000);
//     acc1.displayBalance();
//     acc1.credit(2000);
//     acc1.debit(1000);
//     acc1.displayBalance();
//     return 0;
// }
