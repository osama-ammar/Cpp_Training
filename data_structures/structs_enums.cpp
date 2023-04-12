#include <string>
#include <iostream>
using namespace std;


/*
In C++, a structure is the same as a class except for a few differences. The most important of them is security.
 A Structure is not secure and cannot hide its implementation details from the end user while a class is secure and 
 can hide its programming and designing details

struct is public all time

fast made simple classes

Structures (also called structs) are a way to group several related variables into one place.
Each variable in the structure is known as a member of the structure.
store set of data of similar data types at contiguous memory locations
Unlike an array, a structure can contain many different data types (int, string, bool, etc.).
*/



struct
{
    int phone_number;
    string name;
    float money;
} MYDetails; // variable related to this struct

struct
{
    string brand;
    string model;
    int year;
} myCar1, myCar2; // We can add variables by separating them with a comma here

struct myDataType
{ // This structure is named "myDataType" and can be used many times
    int myNum;
    string myString;
};


//////////////////////////////
//most comman initialization
////////////////////////////////
struct PrivateDetails   //name of the struct
{
    int phone_number;
    string name;
    float money;
};

//struct inside structs
struct PublicDetails   //name of the struct
{
    PrivateDetails person;
    string cat_name;
    float childs_no;
};




struct Point 
{
    int x, y;
};



PrivateDetails enter_details (PrivateDetails x)
{
    cin>>x.money>>x.name>>x.phone_number;
}

// looks like limited items data types
enum Shape
{
    Circle,
    Square,
    Triangle,
    Oval,
    Polygon,
    NumShapes
};

enum Landmarks
{
    pognion = 3,
    nasion = 6,
    sella = 9
};





int main(){

    ////////////////////////////////////////////////////////////////////////////////////
    //initializing a struct var
    struct PrivateDetails omar ; 
    omar.money=200.1;
    omar.phone_number = 98112;

    //or

    struct PrivateDetails wafaa;
    wafaa = {66066 , "wafaa Kamel",2122.5};

    struct PublicDetails fofa;
    fofa = {wafaa , "catty" ,6};
    cout<<fofa.person.name<<endl;



    //array of structs
    struct Point array[10];
    array[0] = {5,3};   //every element of the array is a struct that have 2 members x and y 
    array[1].x = 11;
    array[1].y = 35;
    array[2] = {5,8};



    //////////////////////////////////////////////////////////////////////////////////////
    // getting the index
    Landmarks land = (Landmarks)iter;
    cout << "land mark : " << land << endl;

    // getting the value
    Landmarks prand = nasion;
    cout << "prand mark : " << prand << endl;

    // iterating through enum




    return 0;
}
