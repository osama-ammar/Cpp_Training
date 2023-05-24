#include <iostream>
#include <string>
using namespace std;
#include <cstring>
#include <vector>
/*
dynamic array : normally the array in fixed size but to make it dynamic (flexible in size)
                you can make it in dynamic memory (heap) by making a new array in heap (that has bigger size ) and move the values of the 1st array
                to this new array and delete the old array

                -as you remember , dynamic memory accessed in run time(dynamically) so you can make an array that the user can control its size


Array List :
            insertion : Bad
            Removal : Bad
            Access time : fixed (retreive time) h+i*c
            size : fixed
            ex ( vector) :Vectors are same as dynamic arrays with the ability to resize itself automatically when an element 
                            is inserted or deleted, with their storage being handled automatically by the container



            access time of Array is  O(n)
            search  in Array is  O(n) as in linear search or O(logn) as in binary search

*/
template <class T>
class ArrayList
{

private:
    int capacity;
    int no_of_items;
    T *arr;

    void expand()
    {
        capacity *= 2;

        // making new array with new capacity
        T *new_arr = new T[capacity];

        // copying arr values to new_arr
        for (int i = 0; i < no_of_items; i++)
            new_arr[i] = arr[i];

        // deleting the old array  that arr points to
        delete[] arr;

        // arr will carry the address new arr
        // now arr and new_arr points to the same array
        arr = new_arr;
    }

public:
    ArrayList(int capacity = 3)
    {
        this->capacity = capacity;
        no_of_items = 0;
        arr = new T[capacity];
        cout << "a new array with capacity : " << capacity << "  is constructed" << endl;
    }

    ~ArrayList()
    {
        // to delete an array from heap we .....
        delete[] arr;
    }

    void add_to_last(T value)
    {
        if (no_of_items == capacity)
        {
            cout << "array is full!....expanding..." << endl;
            expand();
        }

        arr[no_of_items] = value;
        no_of_items++;
    }

    void add_to_first(T value)
    {
        if (no_of_items == capacity)
        {
            cout << "array is full!....expanding..." << endl;
            expand();
        }

        for (int i = no_of_items - 1; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[no_of_items] = value;
        no_of_items++;
    }

    void remove_from_first()
    {
        for (int i = 0; i <= no_of_items - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        no_of_items--;
    }

    void remove_from_last()
    {
        // we will move last index a step backward
        // but we didn't delete the last value ???  consider it garabage since the array already carry garbage values in free locations ..do you remember??
        no_of_items--;
        // arr[no_of_items]=null;
    }

    bool search(T value)
    {
        cout << "no of items found : " << no_of_items << endl;
        for (int i = 0; i < no_of_items; i++)
        {

            if (arr[i] == value)
            {
                return true;
                cout << "exists" << endl;
            }
        }
        return false;
    }

    int getCapacity()
    {
        return capacity;
    }

    void print()
    {
        for (int i = 0; i <= no_of_items; i += 1)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void setCap(int cap)
    {
        this->cap = cap;
    }
};


//////////////////////////////////////////////////////////////////////////////
template <class T>
void print_vector(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << " ; and has size of :" << v.size() << endl;
}
///////////////////////////////////////////////////////////////////////////////


int main()
{

    // ArrayList<int> koko(7);
    // for (int i = 0; i < koko.getCapacity(); i++)
    // {

    //     koko.add_to_last(i*2);
    // }
    // koko.print();
    // koko.remove_from_first();
    // koko.print();
    // koko.remove_from_last();
    // koko.print();
    // koko.search(8);

    // exploring vector operations
    vector<float> v;
    for (int i = 0; i < 8; i++)
    {
        v.push_back(i);
    }
    v.insert(v.begin(), 33.3);
    //    v.erase(v.end());

    print_vector<float>(v);




/*
    int var : iterable - Copies each element of num to the var variable in each iteration. This is not good for computer memory.
    int &var : iterable - Does not copy each element of num to var. Instead, accesses the elements of num directly from num itself. This is more efficient.

    Note: If we are not modifying the [array / vector / collection] within the loop, it is better to use the const keyword in range declaration.

*/

    // for in c++ with iterable
    for (const float &item : v)
    {
        cout << item << " " << endl;
    }




    cout << "element at index 3 is : " << v.at(3) << " or " << v[3] << endl;

    // change vector elements
    v[3] = 0.111;
    v.pop_back();
    print_vector<float>(v);

    return 0;
}
