#include <iostream>
#include <string>

using namespace std;

class Account {
    public:
        virtual void deposite(double amount) = 0;
        virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account {
    private:
        double balance;

    public:
        SavingAccount() {
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout << "Deposited: " << amount << "in saving account new balance is : " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdraw: " << amount << "from saving account, now balance is:  " << balance << endl; 
            }else{
                cout << "withdraw is not possible due to insuffucent amount" << endl;
            }
        }
};

class currentAccount : public Account {
    private:
        double balnace;

    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout << "Deposited: " << amount << "in current account new balance is : " << balance << endl;
        }

        void withdraw(double amount){
            if(balance >= amount){
                balnace -= amount;
                cout << "Withdraw: " << amount << "from current account now balance is ->  " << balance << endl;
            }else{
                cout << "Withdraw that is not possible due to " << amont << "is greater than " << balance << endl;
            }
        }
};

class FixedTermAccount : public Account {
    private:
        double balance;
    
    private:
        FixedTermAccount() {
            balance = 0;
        }

        void deposite(double amount){
            balance += amount;
            cout << "Deposited: " << amount << "in fixed term account" << endl;
        }

        void withdraw(double amount){
            throw logic_error("withdraw is not allowed in fixed term account");
        }
};

class BankClient {
    private:
        vector<Account*> accounts;

    public:
        BankClient(vector<Account*> accounts){
            this -> accounts = accounts;
        }

        void processTransactions(){
            for(Account* acc : accounts){
                acc -> deposite(1000);

                try {
                    acc -> withdraw(500);
                }catch(const logic_error& e){
                    cout << "Error: " << e.what() << endl; 
                }
            }
        }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient client(accounts);
    client.processTransactions();

    for(Account* acc : accounts){
        delete acc;
    }

    return 0;
}