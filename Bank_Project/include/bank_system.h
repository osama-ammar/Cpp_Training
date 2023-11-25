
#ifndef HEADER_FILE_H
#define HEADER_FILE_H
#include <string>
#include <iostream>
using namespace std;
#include <fstream>
//#include "defaultconfig.h"
#include "data_files.h"




// overloading : functions of same name / but different signature(arguments types & no)
// oveRRiding : functions of SSame name / SSame signature(arguments types & no) / & inheritance occuar

// a class contain all validation methods that are needed by other classes
class Validations
{
public:
    static bool check_name(string name)
    {
        // this method returns the index of 1st character in name string that doesn't match any char in the argument string
        size_t fond_index = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ");

        // npos is an index and =-1 by default meaning (no match)
        if (name.length() <= 20 && name.length() >= 5 && fond_index != std::string::npos)
        {
            cout << "accepted name entered" << endl;
            return true;
        }
    }

    static bool check_bassword(string password)
    {
        if (password.length() <= 20 && password.length() >= 8)
        {
            return true;
        }
        cout << "bassword should be <20 and >8 characters" << endl;
    }

    static void get_file_info(string filename)
    {
        ifstream myfile(filename, ios::out | ios::app);
        string line;
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << '\n';
            }
        }
    }
};




//template< class T > 
class Person
{
private: // type here parameters that will be inheritted , can be used in parent  only
    string name;
    int id;
    double current_salary;
    double min_salary;
    string password;
    static int order; //  member shared between any object n the class
                      //  will have one place in memory shared between objects
                      // cannot take value zero inside the class ... cannot be zeroed in file.h file but in file.cpp

    friend void modify(Person &obj)
    { // this is called friend function -not a class member - used to access private members and modify them
        obj.name = "lion";
        cout << obj.name << endl;
    }

public: // can be used anywhere
    Person()
    {
        this->id = 0;
        this->order++;
    }

    Person(string name, int id, string password, double current_salary, double min_salary)
    {
        this->name = name;
        this->id = id;
        this->password = password;
        this->current_salary = current_salary;
        this->min_salary = min_salary;
    }

    // can be called without making an object by (Person::static_method)
    // works only on static variables not normal ex( orders );
    static void static_method()
    {
        cout << "no need to make a member to call me" << endl;
    }

    //////////////
    // setters
    //////////////
    void setName(string name)
    {
        // this method returns the index of 1st character in name string that doesn't match any char in the argument string
        // npos is an index and =-1 be default meaning (no match)
        if (Validations::check_name(name))
        {
            this->name = name;
            return;
        }

        cout << "name should be at least 5 characters and not longer than 20 characters" << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }
    void set_salary(double salary)
    {
        this->current_salary = salary;
    }

    void setPassword(string password)
    {
        if (Validations::check_bassword(password))
        {
            this->password = password;
        }
    }

    //////////////
    // Getters
    //////////////
    string getName()
    {
        return this->name;
    }

    int getId()
    {
        return this->id;
    }

    double get_salary()
    {
        return this->current_salary;
    }

    double get_min_salary()
    {
        return this->min_salary;
    }


    // getting information about the client from  a file
    static void get_Person_info(Person client)
    {
        string person_name = client.getName();
        fstream client_file;
        client_file.open(DATA_DIR + person_name + ".txt", ios::in);
        if (client_file.is_open())
        {
            std::string line;
            while (getline(client_file, line))
            {
                std::cout << line << "\n";
            }
        }
        client_file.close();
    }


    void getOrder()
    {
        cout << "order : " << this->order << endl;
    }
    ///////////
    // Other
    ///////////
    void update_balance_file(double new_balance)
    {
        ofstream myfile;
        string file_name = this->getName() + ".txt";

        // making a txt file an append text in it append(std::ios_base::app) update(ios::in)

        string data_path ="D:/Code_store/Cpp_Training/Bank_Project/data/";//std::getenv("DATA_PATH");//this line stopped the program in a very strange way

        myfile.open(data_path + file_name);
        myfile << "this fille is for : "
            << this->getName() << "\n"
            << "id : " << this->getId() << "\n"
            << "balance : " << new_balance << endl
            << "current salary : " << this->current_salary << "\n"
            << "min salary : " << this->min_salary << "\n";

        myfile.close();
    }

    ~Person()
    {
        cout << "I'm destroyed" << endl;
    }
};

class Client : public Person //, public FileManager
{
private:
    double balance;

public:
    static int count;

    Client(
        string name,
        int id,
        string password,
        double balance,
        double current_salary) : Person(name, id, password, balance, current_salary)
    {
        std::cout << "adding a new client" << std::endl;
        this->balance = balance;
        this->count += 1;
        this->update_balance_file(balance);
        //auto obj =this;
        //this->addClient(obj);
    
    }


    void set_balance(double balance)
    {
        this->balance = balance;
        this->update_balance_file(balance);
    }

    int get_balance()
    {
        return this->balance;
    }


    void check_balance()
    {
        cout << "your current balance is : " << this->balance << endl;
    }

    double deposit(double money)
    {
        balance += money;
        cout << "money added...your balance now is : " << balance << endl;
        this->update_balance_file(balance);
        return balance;
    }

    double withdraw(double money)
    {
        if (money <= balance)
        {
            balance -= money;
            cout << "money subtracted...your balance now is : " << balance << endl;
            this->update_balance_file(balance);
            return balance;
        }
        else
        {
            cout << "amount subtraction exceeded your balance" << endl;
            return balance;
        }
    }

    double transferMoney(Client &a, double money)
    {
        if (money <= balance)
        {
            a.deposit(money);
            balance -= money;
            cout << money << " dollars has been sent to " << a.getName() << endl;
            this->update_balance_file(balance);
            return balance;
        }
        else
        {
            cout << "amount cannot be sent" << endl;
            return balance;
        }
    }
};

class Employee : public Person
{
private:
    double balance;

public:
    Employee(
        string name,
        int id,
        string password,
        double balance,
        double current_salary,
        const double min_salary = 5000) : Person(name, id, password, current_salary, min_salary)
    {
        this->balance = balance;
        this->update_balance_file(balance);
    }


    void  add_client(Client& client){};

    Client* search_id(int id){};

    void list_all_clients(){};

    void view_info(){};
    
    void edit_client_info(int id, string name, string password, double balance){};


    int get_balance()
    {
        return this->balance;
    }





};

class Admin : public Person
{

private:
    double balance;
    const double min_salary = 12000;

public:
    Admin(
        string name,
        int id,
        string password,
        double balance,
        double current_salary, double min_salary) : Person(name, id, password, current_salary, min_salary)
    {
        this->balance = balance;
        this->update_balance_file(balance);
    }

    int get_balance()
    {
        return this->balance;
    }


    void set_employee_salary(Employee *employee, double salary)
    {
        employee->set_salary(salary);
    }


    void  add_emplyee(Employee& employee){};

    Employee* search_id(int id){};

    void list_all_employees(){};

    void view_info(){};
    
    void edit_employee_info(int id, string name, string password, double balance){};




};
#endif