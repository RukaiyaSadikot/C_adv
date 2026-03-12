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
        
        Bank(){
            cout << "Enter account number :";
            cin >> accnumber;
            cin.ignore();
            cout << "Enter Account holder name :";
            cin.getline(holdername, 50);
            cout << "Enter account balance :";
            cin >> balance;
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


