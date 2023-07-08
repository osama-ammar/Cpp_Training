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
                                            -their methods are abstract(pure virtual function so should be overridden by child class)

*/
class DataSourceInterface
{
    public :
        vector<Client> clients_vector;

        virtual void addClient(Client new_client)=0;
        virtual void addEmployee(Employee new_employee)=0;
        virtual void addAdmin(Admin new_admin)=0;
        virtual vector<Client> getAllClients( Client &client)=0;
        //virtual vector<Employee>getAllEmployees()=0;
        //virtual vector<Employee>getAllAdmins()=0;
        virtual void removeAllClients()=0;

        virtual void removeAllEmployees()=0;
        virtual void removeAllAdmins()=0;
};

////////////////////////////////////////////////
////////////////////////////////////////////////

/*
this class is used to implement Data Source Interface class

*/
class FileManager : public DataSourceInterface
{
        void addClient(Client new_client )
            {
                    ofstream myfile;
                    string clients_file ="Clients.txt";
                    //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
                    myfile.open(clients_file,std::ios_base::app);
                    myfile<<"this fille is for : "
                        <<new_client.getName()<<"\n"
                        <<"id : "<<new_client.getId()<<"\n"
                        <<"balance : "<<new_client.get_balance()<<endl
                        <<"current salary : "<<new_client.get_min_salary()<<"\n"
                        <<"min salary : "<<new_client.get_min_salary()<<"\n"
                        <<"==================================================="<<endl;      
                                                
                    myfile.close();
            }



        void addEmployee(Employee new_employee)
        {
            ofstream myfile;
            string employees_file ="Employees.txt";
            //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
            myfile.open(employees_file,std::ios_base::app);
            myfile<<"this fille is for : "
                <<new_employee.getName()<<"\n"
                <<"id : "<<new_employee.getId()<<"\n"
                <<"balance : "<<new_employee.get_balance()<<endl
                <<"current salary : "<<new_employee.get_min_salary()<<"\n"
                <<"min salary : "<<new_employee.get_min_salary()<<"\n"
                <<"==================================================="<<endl;      
                                        
            myfile.close();

        }



        void addAdmin(Admin new_admin)
        {
        
            ofstream myfile;
            string admins_file ="Admins.txt";
            //making a txt file an append text in it append(std::ios_base::app) update(ios::in)
            myfile.open(admins_file,std::ios_base::app);
            myfile<<"this fille is for : "
                <<new_admin.getName()<<"\n"
                <<"id : "<<new_admin.getId()<<"\n"
                <<"balance : "<<new_admin.get_balance()<<endl
                <<"current salary : "<<new_admin.get_min_salary()<<"\n"
                <<"min salary : "<<new_admin.get_min_salary()<<"\n"
                <<"==================================================="<<endl;      
                                        
            myfile.close();
        }


        vector<Client> getAllClients( Client &client){

            this->clients_vector.push_back(client);
            string person_name = client.getName();
            fstream clients_file;
            clients_file.open("clients.txt", ios::in);
            if (clients_file.is_open())
            {
                //parsing through lines of the file 
                //getting lines that contain "name"
                // getting the chars after "name" and display it
                std::string line;
                while (getline(clients_file, line))
                {
                    size_t str_pos = line.find("name");
                    if (str_pos != string::npos)
                    {

                        string person_name = line.substr(str_pos+5,string::npos);
                        std::cout << "found a name : " <<person_name<< "\n";
                    }
                }
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


        void removeAllEmployees(){};
        void removeAllAdmins(){};

};


// to parse data files
class Parser
{


};




//save and get from txt files contains
class FilesHelper
{



};