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
        Author(string name, string email, string gender)
        {
            this->name = name;
            this->email = email;
            this->gender = gender;
        }

        void setName(string name){
            this->name = name;
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
        Book(string title, int price, int quantity , Author author)
        {
            this->title = title;
            this->price = price;
            this->quantity = quantity;
            this->author = author;
        }

        void setTitle(string title){
            this->title = title;
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




