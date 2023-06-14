/*
Design patterns  repeated solutions to repeated pattern of problems

            1-creational design pattern: concerning creation of class and objects
                                    ex : singleton , factory , prototype

            2-structural design pattern:concerning composition of class and objects
                                    ex : Adapter , bridge , proxy


            3-behavioral design pattern:concerning interaction between class and objects
                                    ex : observer , visitor


*/



#include <iostream>
#include <string>
using namespace std;

//you can make many object of this class but in some cases , I need one object only that can be controlled from many places
// ex: google user that have specific setting in one computer ... if he moved to another computer he will find the last setting he selected
// ex) admin case : when you  have only one admin
class Setting
{
    private:
        int value;
        bool dark_mode;

    public:
        Setting(){}

        void set_value(int value)
        {
            this->value = value;
        }

        void set_dark_mode(bool dark)
        {
            this->dark_mode = dark;
        }

        int get_value()
        {
            return this->value;
        }

        bool get_dark_mode()
        {
            return this->dark_mode;
        }

};


/*
to apply sigleton pattern we will :
            1- make private constructor
            2- make private object
            3- make public method
*/
class SettingSingle
{
    private:
        int value;
        bool dark_mode;
        //
        SettingSingle(){}
        static SettingSingle* my_settting;

    public:
        //
        static SettingSingle * get_my_setting()
        {
            if (my_settting==nullptr)
            {
                my_settting = new SettingSingle;
            }
            //
            return my_settting;
        }

        void set_value(int value)
        {
            this->value = value;
        }

        void set_dark_mode(bool dark)
        {
            this->dark_mode = dark;
        }

        int get_value()
        {
            return this->value;
        }

        bool get_dark_mode()
        {
            return this->dark_mode;
        }

};


// we assign nullptr to this static object because we cannot do this inside the class , because it's static
SettingSingle * SettingSingle::my_settting=nullptr;




int main()
{
    Setting normal_seeting1 ;
    normal_seeting1.set_dark_mode(true);
    normal_seeting1.set_value(33);

    Setting normal_seeting2 ;
    normal_seeting2.set_dark_mode(true);
    normal_seeting2.set_value(33);




    //
    SettingSingle * normal_seeting1 ;
    normal_seeting1.set_dark_mode(true);
    normal_seeting1.set_value(33);

    SettingSingle * normal_seeting2 ;
    normal_seeting2.set_dark_mode(true);
    normal_seeting2.set_value(33);




    return 0;
}