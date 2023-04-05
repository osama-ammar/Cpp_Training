#include <iostream>
#include <string>
using namespace std;




class Account{

    private:
        string name;
        string id;
        int balance;


    public:
        Account(){
            name = "unkknown";
            id = "0000";
            balance = 0;
            int* p_balance = &balance;
        }

        Account(string n , string id ){
            name = n;
            id = id;
        }

        Account(string n , string id , int b){
            name = n;
            id = id;
            balance = b ;
        }

        string getName(){
            return name;
        }
        string getId(){
            return id;
        }
        int getBalance(){
            return balance;
        }        


        int credit(int money)
        {

            balance += money;
            cout << "money added...your balance now is : "<<balance <<endl;
            return balance;
        }

        int debit(int money)
        {
            if (money <= balance)
                {
                balance -= money;
                cout << "money subtracted...your balance now is : "<<balance <<endl;
                return balance;
                }
            else {
                cout << "amount subtraction exceeded your balance" <<endl;
                return balance;
            }
        }


        int transferMoney(Account &a , int money)
        {
            if (money <=balance)
            {
                a.credit(money);
                balance-=money;
                cout << money<< " dollars has been sent to "<<a.getName() <<endl;
                return balance;
            }
            else {
                cout << "amount cannot be sent" <<endl;
                return balance;
            }



        }









};
