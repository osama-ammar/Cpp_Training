/*
    allocators are objects used in encapsulating memory management
    std::allocator()------it's a class that is part of the standard library....and has 6 member functions(address,construct,max_size,destroy,,allocate,deallocate)



    deallocate : deallocate space of memory
    destroy : destroy -destruct an object in the allocated storge 



*/

#include <iostream>
using namespace std;





int main(){

    //decalare a variable of type allocator of type int 
    allocator<int> myAllocator;

    //allocate space fro 4 integers
    int* arr =  myAllocator.allocate(4);

    arr[0] =3;
    arr[1] =6;
    arr[2] =32;

    //dealllcate space for 4 ints
    myAllocator.deallocate(arr,4);



    cout<<*arr<<endl;
    cout<<*arr<<endl;

}





















