
#include <iostream>
#include <string>
using namespace std;
#include <list>
#include "linked_list.hpp"

// linked list is better than arry in: flexible size - easy to add or delete items ,it doesn't allocate cosequetive places in memory but---it slowely access to items
// each node in the linked list is (variable:that carry data , pointer:that carry address to the next node) ..each node occupies two places in memory
// the first node in the linked lidt is only a pointer called head, the final node containn a variable and a pointer pointing to null (not poiting to any thing)
// linked list example in C++ STL : is List
/*
note: I noticed that , with head node  we do not use (head->data) or (head->next).....so treat head as only a pointer the first node ...and it's used directly

    head=xnode means.that head will point to this node
    head=xnode.next...means head will point to the node next to this node
*/




/*
every c++ data structure in stl has a member called iterator
you can use this iterator to print or show the content of this DS as follows
*/
void showLlist(list<int> input_list)
{
    //accessing the iterator member in list class
    list<int>::iterator it;

    for (it = input_list.begin(); it != input_list.end(); it++)
    {
        cout << *it << "-->";
    }
    cout << endl;
}





int main()
{

    // using my oop implementation
    // LinkedList linked_list;
    // for (int i = 0; i < 30; i++)
    // {
    //     linked_list.add_to_first(i);
    // }
    // linked_list.print();
    // linked_list.remove_from_first();
    // linked_list.print();
    // linked_list.remove_from_last();
    // linked_list.print();
    //////////////////////////////////////////////////////////////////////////////
    // USING c++ stl implementation od LinkedList (List)

    list<int> cpp_list;
    for (int i = 0; i < 10; i++)
    {
        cpp_list.push_back(i);
    }

    showLlist(cpp_list);
    cpp_list.reverse();
    showLlist(cpp_list);
    cpp_list.sort();
    cout<<cpp_list.size()<<endl;
    cpp_list.
        /////////////////////////////////////////////////////////////////////////////

        ////    // using my functional implementation
        // int list[]={22,34,55,66,67,68,99};
        //  for (int i : list)
        //      {insert_node(i);
        //      }
        //  //delete_last();
        //  //modify(21);
        //  //insert_begin(222);
        //  //delete_begin();
        //  insert_begin(100);
        //  display ();

        return 0;
};
