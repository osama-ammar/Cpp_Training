
/*
Clean code  : readable , maintainable code

to achieve this :
            - naming conventions
            - comments
            - SOLID principles
            ---


    SOLID Principles :
        - Single responsibility
                    each function is reponsible of one functionality

        - Open closed domain
                    code is open for extension , closed for modification

        - Liskov suubstitution
                    (in inheritance)  : class A can inherit from class B , if class A ~can replace class B ex(client cannot inherit from manger)

        - interface seggregation
                    (in oop) interface looks like Abstract class in cpp
                    you should seggregate interfaces ex(phone class can inherit from camera , calender , phone call)
                                                    but not from a class that collect all these options

        -Dependency inversion 
                    related to oop , low and high level modules .. connect between them with abstract class
                    ex()

*/



























/////////////////////////////////////////////////////////////////////////////////////////////////
/*
// Dependency inversion:
here is the lamp and switch example in C++. Imagine you have a class that represents a lamp, 
and it depends on a class that represents a switch. If you write something like this:
Then you have a problem: the Lamp class depends on the Switch class, which is a low-level module. 
This means that if you want to change the way you control the lamp, such as using a remote control
 or a voice command, you have to change the Lamp class as well. This violates the dependency inversion principle.
To fix this, you can introduce an abstraction between them, such as an interface:


*/
#include <iostream>
using namespace std;


class Switch {
    private:
        bool state;

    public:
        Switch() {
            state = false; // off by default
        }

        void on() {
            state = true;
            std::cout << "Switch turned on" << std::endl;
        }

        void off() {
            state = false;
            std::cout << "Switch turned off" << std::endl;
        }
};



class Lamp  {
    private:
        Switch* switch;

    public:
        Lamp() {
            switch = new Switch();
        }

        void turnOn() {
            switch->on();
        }

        void turnOff() {
            switch->off();
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Now, both the Lamp and the Switch classes depend on the ISwitchable interface, 
which is an abstraction. This way, you can easily replace the Switch class with another
 implementation of the interface, such as a RemoteControl or a VoiceCommand, 
 without changing the Lamp class. This follows the dependency inversion principle.

*/

class ISwitchable {
    public:
        virtual void on() = 0;
        virtual void off() = 0;
};

class Lamp {
    private:
        ISwitchable* switchable;

    public:
        Lamp(ISwitchable* switchable) {
            this->switchable = switchable;
        }

        void turnOn() {
            switchable->on();
        }

        void turnOff() {
            switchable->off();
        }
};

class Switch : public ISwitchable {
    private:
        bool state;

    public:
        Switch() {
            state = false; // off by default
        }

        void on() override {
            state = true;
            std::cout << "Switch turned on" << std::endl;
        }

        void off() override {
            state = false;
            std::cout << "Switch turned off" << std::endl;
        }
};