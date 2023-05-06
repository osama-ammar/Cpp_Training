#include <string>
#include <iostream>
using namespace std;
#include <fstream>
// overloading : functions of same name / but different signature(arguments types & no)

// oveRRiding : functions of SSame name / SSame signature(arguments types & no) / & inheritance occuar


// a class contain all validation methods that are needed by other classes
class Validations{
        public:
            static int check_name(string name){
                // this method returns the index of 1st character in name string that doesn't match any char in the argument string
                size_t fond_index = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");

                // npos is an index and =-1 be default meaning (no match)
                if (name.length()<=20 && name.length()>=5 && fond_index != std::string::npos)
                {
                    cout<< "accepted name entered"<< endl;
                    return true;
                }   
            }   


            static int check_bassword(string password)
            {
                if (password.length()<=20 && password.length()>=8 )
                {
                    return true;
                }           
                cout<<"bassword should be <20 and >8 characters"<<endl;
            }


            static void get_file_info ( string filename){
                ifstream myfile(filename, ios::out | ios::app );
                string line;
                if (myfile.is_open())
                {
                    while (getline(myfile,line) )
                    {
                    cout << line << '\n';
                    }
                }
            }



};



class Person 
{
    private: // type here parameters that will be inheritted , can be used in parent  only
        string name;
        int id;

        string password;
        static int order ;  //  member shared between any object n the class
                            //  will have one place in memory shared between objects
                            //cannot take value zero inside the class ... cannot be zeroed in file.h file but in file.cpp

		friend void modify(Person &obj)
		{    // this is called friend function -not a class member - used to access private members and modify them
		obj.name="lion";
		cout<<obj.name<<endl;
		}


    public: //can be used anywhere

        Person(){
            this->id = 0;
            this->order++;
        }

        Person(string name, int id, string password){
            this->name = name;
            this->id = id;
            this->password = password;

        }

        //can be called without making an object by (Person::static_method)
        //works only on static variables not normal ex( orders );
        static void static_method()
        {
            cout << "no need to make a member to call me" << endl;
        }




        void setName(string name)
        {
            // this method returns the index of 1st character in name string that doesn't match any char in the argument string
            // npos is an index and =-1 be default meaning (no match)
            if (Validations::check_name(name))
            {
                this->name = name;
                return;
            }   

            cout<<"name should be at least 5 characters and not longer than 20 characters"<< endl;
        }

        string  getName(){
            return this->name;
        }

        void setId(int id)
        {
            this->id = id;
        }



        void setPassword(string password)
        {
            if (Validations::check_bassword(password) )
            {
                this->password=password;
            }
        }

        int getId()
        {
            return this->id;
        }

        void getInfo() //this method will be overridden ( modified by the child to extend it with additional  feature)
        {
            cout << "name : " << this->name << endl;
            cout << "id : " << this->id << endl;
            cout << "password : " << this->password << endl;
        }

        void getOrder()
        {
            cout << "order : " << this->order<< endl;
        }




        ~Person(){
            cout<<"I'm destroyed"<<endl;
        }
};




class Client : public Person
{
    private :
        double balance;

    public:
        Client (string name, int id, string password,double balance) : Person( name,  id,  password)
        {
            this->balance =balance;
            ofstream myfile;
            string file_name =name + ".txt";
            myfile.open("file_name");
            myfile<<"this fille is for : "<<"\n"<<name<<"\n"<<id<<"\n"<<balance<<endl;
            myfile.close();
    
        }

        void set_balance (double balance)
        {
            this->balance = balance;
        }
        void check_balance ()
        {
            cout<<"your current balance is : "<<this->balance<<endl;
        }




        double deposit(double money)
        {
            balance += money;
            cout << "money added...your balance now is : "<<balance <<endl;
            return balance;
        }


        double withdraw(double money)
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


        double transferMoney(Client &a , double money)
        {
            if (money <=balance)
            {
                a.deposit(money);
                balance-=money;
                cout << money<< " dollars has been sent to "<<a.getName() <<endl;
                return balance;
            }
            else {
                cout << "amount cannot be sent" <<endl;
                return balance;
            }


};



class Employee : public Person
{
    private :
        double balance;
        double salary;

    public :
        Employee (string name, int id, string password,double balance,double salary) : Person( name,  id,  password)
        {
            this->balance = balance;
            this->salary = salary;
        }



};


class Admin : public Person
{

    private :
        double balance;
        double salary;

    public :
        Admin (string name, int id, string password,double balance,double salary) : Person( name,  id,  password)
        {
            this->balance = balance;
            this->salary = salary;
        }

};

