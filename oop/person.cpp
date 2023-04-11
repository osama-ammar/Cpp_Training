#include <string>
#include <iostream>
using namespace std;




class Person 
{
    protected: //can be used in parent and child only
        string name;
        int id;
        int age;

    public: //can be used anywhere

        Person(){
            this->id = 0;
        }

        Person(string name, int id, int age){
            this->name = name;
            this->id = id;
            this->age = age;
        }

        void setName(string name)
        {
            this->name = name;
        }

        void setId(int id)
        {
            this->id = id;
        }

        void setAge(int age)
        {
            this->age = age;
        }

        int getId()
        {
            return this->id;
        }

        void getInfo() //this method will be overridden ( modified by the child to extend it with additional  feature)
        {
            cout << "name : " << this->name << endl;
            cout << "age : " << this->age << endl;
            cout << "id : " << this->id << endl;
        }


        ~Person(){
            cout<<"I'm destroyed"<<endl;
        }
};

// if the child don't have a method you  call , he will get it from his parent
class Teacher : public Person
{
    protected:
        int salary;

    public:
        Teacher(){
            this->salary=4000;
        }

        Teacher(string name, int id, int age,int salary) : Person(name,id,age) //////
        {
            this->salary=salary;
        }
        void setSalary(int salary)
        {
            this->salary = salary;
        }

        int getSalary()
        {
            return this->salary;
        }

        void getInfo() ////////////////
        {
            Person::getInfo();
            cout<<"Salary : "<<this->salary<<endl;
        }



};