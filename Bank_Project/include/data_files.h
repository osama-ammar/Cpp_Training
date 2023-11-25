
#ifndef HEADER_FILE_H
#define HEADER_FILE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "bank_system.h"

using namespace std;
/*
    - contains classes for files and data handling
*/


/*
this class will be used as abstract class : only to represent the general concept
                                            - it cannot be instantiated
                                            - their methods are abstract(pure virtual function so should be overridden by child class)
*/
class DataSourceInterface
{
    public :

        //pure virtual fn : must be overridden by child class  || virtual function : can be overridden by child class
        virtual void addClient(Client new_client)=0;
        virtual void addEmployee(Employee new_employee)=0;
        virtual void addAdmin(Admin new_admin)=0;
        virtual vector<Client> getAllClients()=0;
        //virtual vector<Employee>getAllEmployees()=0;
        //virtual vector<Employee>getAllAdmins()=0;
        virtual void removeAllClients()=0;
        virtual void removeAllEmployees()=0;
        virtual void removeAllAdmins()=0;
};

////////////////////////////////////////////////
////////////////////////////////////////////////


//this class is used to implement Data Source Interface class
class FileManager : public DataSourceInterface
{
    public:
        vector<Client> clients_vector;
        vector<Employee> employees_vector;
        vector<Admin> admins_vector;


        void addClient(Client* new_client )
            {
                    this->clients_vector.push_back(*new_client);
                    ofstream myfile;
                    string data_path ="D:/Code_store/Cpp_Training/Bank_Project/data/";
                    string clients_file =data_path+"Clients.txt";
                    //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
                    // each line in the text contain all info of one client
                    myfile.open(clients_file,std::ios_base::app);
                    myfile<<"this fille is for : "
                        <<new_client->getName()<<"//"
                        <<"id : "<<new_client->getId()<<"//"
                        <<"balance : "<<new_client->get_balance()<<endl
                        <<"current salary : "<<new_client->get_min_salary()<<"//"
                        <<"min salary : "<<new_client->get_min_salary()<<"//"
                        <<"==================================================="<<endl;      
                                                
                    myfile.close();
            }



        void addEmployee(Employee new_employee)
        {
            this->employees_vector.push_back(new_employee);
            ofstream myfile;
            string employees_file ="Employees.txt";
            //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
            myfile.open(employees_file,std::ios_base::app);
            myfile<<"this fille is for : "
                <<new_employee.getName()<<"//"
                <<"id : "<<new_employee.getId()<<"//"
                <<"balance : "<<new_employee.get_balance()<<endl
                <<"current salary : "<<new_employee.get_min_salary()<<"//"
                <<"min salary : "<<new_employee.get_min_salary()<<"//"
                <<"==================================================="<<endl;      
                                        
            myfile.close();

        }



        void addAdmin(Admin new_admin)
        {
            this->admins_vector.push_back(new_admin);
        
            ofstream myfile;
            string admins_file ="Admins.txt";
            //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
            myfile.open(admins_file,std::ios_base::app);
            myfile<<"this fille is for : "
                <<new_admin.getName()<<"//"
                <<"id : "<<new_admin.getId()<<"//"
                <<"balance : "<<new_admin.get_balance()<<endl
                <<"current salary : "<<new_admin.get_min_salary()<<"//"
                <<"min salary : "<<new_admin.get_min_salary()<<"//"
                <<"==================================================="<<endl;      
                                        
            myfile.close();
        }


        vector<Client> getAllClients(){

            vector<Client> clients_vector;
            fstream clients_file;
            clients_file.open("clients.txt", ios::in);
            if (clients_file.is_open())
            {
                //parsing through lines of the file 
                //getting lines that contain "name"
                // getting the chars after "name" and display it
                // std::string line;
                // while (getline(clients_file, line))
                // {
                //     //get client infor from a line --split it -- save it as a client instance
                //     string client_info=split(line);
                //     Client client();
                //     clients_vector.push_back(client);

                // }
            }
            clients_file.close(); 

            return this->clients_vector;
        }


        //vector<Employee>getAllEmployees(){};
        //vector<Employee>getAllAdmins(){};


        void removeAllClients()
        {
            this->clients_vector.clear();
            fstream clients_file;
            // open file in write mode
            clients_file.open("clients.txt",ios::out | ios::trunc);
            if (clients_file.is_open())
            {
                //clearing the clients file
                clients_file.clear();
            }
            clients_file.close(); 

        }


        void removeAllEmployees()
        {
            this->employees_vector.clear();
            fstream clients_file;
            // open file in write mode
            clients_file.open("employees.txt",ios::out | ios::trunc);
            if (clients_file.is_open())
            {
                //clearing the clients file
                clients_file.clear();
            }
            clients_file.close(); 

        };



        void removeAllAdmins()
        {
            this->admins_vector.clear();
            fstream clients_file;
            // open file in write mode
            clients_file.open("admins.txt",ios::out | ios::trunc);
            if (clients_file.is_open())
            {
                //clearing the clients file
                clients_file.clear();
            }
            clients_file.close(); 

        };

};


// to parse data files
class Parser
{
    public:
        Parser(){};

        static vector<string> split(string line)
        {
            vector<string> line_info;
            size_t name_pos = line.find("name");
            size_t id_pos = line.find("id");
            size_t salary_pos = line.find("salary");
            size_t balance_pos = line.find("balance");
            //check if name_pos != -1 (exist)
            if (name_pos != string::npos)
            {
                string person_name = line.substr(name_pos+5,string::npos);
                string person_id = line.substr(id_pos+5,string::npos);
                string person_salary = line.substr(salary_pos+5,string::npos);
                string person_balance = line.substr(balance_pos+5,string::npos);
                line_info.push_back(person_name);
                line_info.push_back(person_id);
                line_info.push_back(person_salary);
                line_info.push_back(person_balance);
            }
            return line_info;
        };

        static Client parseToClient(string line){};

        static Employee parseToEmployee(string line){};

        static Admin parseToAdmin(string line){};

};




//save and get from txt files contains
class FilesHelper
{
    public:
    FilesHelper(){};

    static void saveLast(string fileName, int id){};

    static int getLast(string fileName){};

    static void saveClient(Client c){};

    static void saveEmployee(string fileName, string lastIdFile, Employee e){};

    static void getClients(){};

    static void getEmployees(){};

    static void getAdmins(){};

    static void clearFile(string fileName, string lastIdFile){};


};
#endif