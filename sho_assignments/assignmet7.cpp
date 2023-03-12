#include <iostream>
using namespace std;



class Vehicle
    {
        public:

            string model;
            string registration_no;
            int speed;
            double fuel_cabacity;
            double fuel_consunption;

            //constractor
            Vehicle(){};  //(default constructor ) made only to avoid error in child class
                        // 

            Vehicle
            (
                string model_ ,
                string registration_no_ ,
                int speed_ ,
                double fuel_cabacity_ ,
                double fuel_consunption_
            )
            {
                model = model_;
                registration_no = registration_no_;
                speed=speed_;
                fuel_cabacity = fuel_cabacity_;
                fuel_consunption = fuel_consunption_;
                cout<<" a new member is added ";
            }


            //class methods
            int calc_fuel_needed (int distance)
            {
                return (distance * fuel_cabacity);
            }

            int distance_covered (int hrs )
            {
                return (hrs * speed);
            }

            void display()
            {
                cout << "Vehicle information :"<<"model : "<<model<<endl<<"registration_no : "<<registration_no<<endl<<"speed : "<<speed<<endl<<"fuel_cabacity : "<<fuel_cabacity<<endl<<"fuel_consunption : "<<fuel_consunption<<endl;
            }

    };

class Truck: public Vehicle
{

    public:


        Truck (int cargo_limit_)
            {
                cargo_limit = cargo_limit_;
            };



        int cargo_limit;


        void set_cargo_limit (int cargo_limit_)
        {
            cargo_limit = cargo_limit_;
        }


        int get_cargo_limit()
        {
            return cargo_limit ;
        }




        void display()
        {
            Vehicle::display();
            cout<<cargo_limit<<endl;
        }


};







int main()
{

    //declaration 

    Vehicle car ("BMW","B1234",300,400,500);
    string car_model = car.model;

    Truck suzuki (211);


    //process
    //car.display();
    suzuki.display();



    //results



    return 0;
}