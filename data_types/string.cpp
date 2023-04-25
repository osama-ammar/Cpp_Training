#include <iostream>
#include <string>
using namespace std;
#include <cstring>
//std::isupper()
//std::islower
//x=std::toupper()
//std::size
//std::isdigit
//std::isspace
//look at std::strcpy and std::strncpy

template <class A , class B>
void print(A input1, B input2)
{
    cout<<input1<<" "<<input2<<endl;
}


void merge(int arr[], int x)
{
    cout << arr<<endl;

}

int main()
{

    string message1 ="this is a message";
    string message2 {"this is a message",6};
    string message3 {5,'h'};
    string message4 {message1,2,6};

    //arr[3]++

    // writing a text in this manner give you many options later
    char text[] {"Hi there my age is 35"};
    char text2[] {"Hello there my age is 29"};   

    //concatenate the 2nd parameter to the first and update the first
    strcat(text,text2);
    //strncat(text,text2,6);
    cout<<text<<"/";

    char *ptr_find=strchr(text,'t');
    cout<<ptr_find<<endl;



    char target='m';
    char *ptr_text=text;

    //cout << strlen(text)<<endl;
    //cout << sizeof(text)<<endl;
    //cout << strcmp(text,text2)<<endl;

    if (strchr(text,target) != NULL)
    {
        cout << "found target "<<target<<"  "<<strchr(text,target)<<endl;
    }

    for (auto i :text){
        //cout << i <<endl;

        if (std::isalpha(i))
        {
            //cout<<"char " <<i<<"  is Alpha"<<endl;
        }


        

    }















}





































