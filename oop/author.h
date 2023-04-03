#include <iostream>
#include <string>
using namespace std;



class Author {
    private:
        string name;
        string email;
        string gender;

    public:

        //default constructor
        Author(){
            name = "unknown";
            email = "unknown";
            gender = "unknown";
        }

        //parameterized constructor
        Author(string n, string e, string g)
        {
            name = n;
            email = e;
            gender = g;
        }

        void setName(string n){
            name = n;
        }


        string getName(){
            return name;
        }

        void showInfo(){
            cout<<name<<endl<<email<<endl<<gender<<endl;
        }

};


class Book {
    private:
        string title;
        Author author;
        int price;
        int quantity;

    public:

        //default constructor
        Book(){
            title = "unknown";
            price = 0;
            quantity = 0;
        }

        //parameterized constructor
        Book(string n, int e, int g , Author a)
        {
            title = n;
            price = e;
            quantity = g;
            author = a;
        }

        void setTitle(string n){
            title = n;
        }


        string getTitle(){
            return title;
        }

        Author getAuthor(){
            return author;
        }


        void showInfo(){
            cout<<title<<endl<<price<<endl<<quantity<<endl;
        }

};




