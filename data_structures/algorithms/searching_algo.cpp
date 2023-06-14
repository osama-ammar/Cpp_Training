#include <iostream>
#include <string>
using namespace std;


//Linear search (log(n))
bool LinearSearch(int arr[],int size,int value)
{
    for (int i=0;i<size;i++)
    {
        if (arr[i]==value)
            return true;
    }
    return false;
}


//Binary search nlog(n)
// considering that , the array is sorted 
bool BinarySearch(int arr[],int size,int value)
{
    int start = 0;
    int end = size-1;

    while (start <= end)
    {
        //setting thr mid location ...in every iteration
        int mid = (start + end) /2;
        if (value==arr[mid] )
            return true;
        if ( value >arr[mid])
            start = mid+1;
        if ( value < arr[mid] )
            end = mid-1;
    }

    return false;
    
}



int main()
{
    int arr [10]={11,12,13,14,15,16,17,18,19,20};

    bool x = BinarySearch(arr,10,21);

    cout<<"x = "<<x<<endl;


    return 0;
}