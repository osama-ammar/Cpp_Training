#include <string>
#include <iostream>
using namespace std;

// overloading : functions of same name / but different signature(arguments types & no)

// oveRRiding : functions of SSame name / SSame signature(arguments types & no) / & inheritance occuar

class Person 
{
    private: // type here parameters that will be inheritted , can be used in parent  only
        string name;
        int id;
        int age;
        int money;
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

        Person(string name, int id, int age){
            this->name = name;
            this->id = id;
            this->age = age;
            this->order++;
        }

        //can be called without making an object by (Person::static_method)
        //works only on static variables not normal ex( orders );
        static void static_method()
        {
            cout << "no need to make a member to call me" << endl;
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

        void getOrder()
        {
            cout << "order : " << this->order<< endl;
        }




		// this is called operator overloading like __add__ in python ?
		int operator + (Person &obj)
			{
			Person sum;
			sum.money=this->money + obj.money;
			return sum.money;
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