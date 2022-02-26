#include <string>
#include <iostream>
#include <fstream>  // for files read write creat //include (of/if)stream
using namespace std;
int main(){
    ofstream myfile;
    myfile.open("model.py");
    myfile<<"add this text. \n";
    myfile.close();
    
    if (myfile.is_open()){  // checking if file can be opened 
        cout<<"this file can be opened"<<endl;
    }
    
    /*while (getline (myfile,line)){  //reading all contents of a file
        cout<<line<<"\n";
    }*/
    myfile.close();
    
    ofstream photo; //for opening binary files
    //outfile.open("card.png",ios::binary)
    
    
    ofstream myfile2("model2.PNG");  //another form for opening
    
//    myfile2<<'"add this text. \n";
//    myfile.close();
    
    
}


