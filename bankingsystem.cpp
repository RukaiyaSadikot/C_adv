#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    int getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayAccountInfo() const
    {
        cout << "Account Number: " << accountNumber
             << ", Holder: " << accountHolderName
             << ", Balance: " << balance << endl;
    }

    virtual void calculateInterest() const
    {
        cout << "Interest calculation not applicable for base account.\n";
    }

protected:
    void setBalance(double newBalance) { balance = newBalance; }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() const override
    {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override
    {
        if (amount <= getBalance() + overdraftLimit)
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawn: " << amount << ", New Balance: " << getBalance() << endl;
        }
        else
        {
            cout << "Withdrawal exceeds overdraft limit!" << endl;
        }
    }

    void calculateInterest() const override
    {
        cout << "Checking accounts do not earn interest.\n";
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal), term(t), interestRate(rate) {}

    void calculateInterest() const override
    {
        double interest = getBalance() * interestRate * term / 12 / 100;
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }
};

int main()
{
    BankAccount *accounts[10];
    int count = 0;
    int choice;

    do
    {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int accNo;
            string name;
            double bal, rate;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            accounts[count++] = new SavingsAccount(accNo, name, bal, rate);
            cout << "Savings Account created.\n";
        }
        else if (choice == 2)
        {
            int accNo;
            string name;
            double bal, limit;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;
            accounts[count++] = new CheckingAccount(accNo, name, bal, limit);
            cout << "Checking Account created.\n";
        }
        else if (choice == 3)
        {
            int accNo, term;
            string name;
            double bal, rate;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            cout << "Enter Term (months): ";
            cin >> term;
            cout << "Enter Interest Rate (%): ";
            cin >> rate;
            accounts[count++] = new FixedDepositAccount(accNo, name, bal, term, rate);
            cout << "Fixed Deposit Account created.\n";
        }
        else if (choice == 4)
        {
            int idx;
            double amt;
            cout << "Enter account index and amount: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < count)
                accounts[idx]->deposit(amt);
            else
                cout << "Invalid index!\n";
        }
        else if (choice == 5)
        {
            int idx;
            double amt;
            cout << "Enter account index and amount: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < count)
                accounts[idx]->withdraw(amt);
            else
                cout << "Invalid index!\n";
        }
        else if (choice == 6)
        {
            for (int i = 0; i < count; i++)
                accounts[i]->displayAccountInfo();
        }
        else if (choice == 7)
        {
            for (int i = 0; i < count; i++)
                accounts[i]->calculateInterest();
        }
    } while (choice != 8);

    cout << "Exiting Banking System...\n";

    for (int i = 0; i < count; i++)
        delete accounts[i];
    return 0;
}
