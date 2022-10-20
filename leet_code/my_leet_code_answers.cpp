
#include <string.h>
#include <iostream>
using namespace std;

//contain my leet code answers


// 3
/* A structure is a user-defined data type in C/C++. A structure creates
 a data type that can be used to group items of possibly different types into a single type. 

looks like a class

*/

/*

Difference between Dot(.) and Arrow(->) operator:  

The Dot(.) operator is used to normally access members of a structure or union.
The Arrow(->) operator exists to access the members of the structure or the unions using pointers.

Simply saying: To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.

*/





/* 
, Linked List is a linear data structure. Unlike arrays, 
linked list elements are not stored at a contiguous location; 
the elements are linked using pointers. They include a series of
 connected nodes. Here, each node stores the data and the address of the next node

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next; //means: next is a pointer to a node structure, and indicates the next item in the list
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* newList = new ListNode;
        
        for (int i ; i<leng ; i++){
            for (int j ; j<leng ; j++){
               if( list1[i] <= list2[j]){
                   
                   list3.append i;
                   
                   else{list3.append j; }
                   
               }
          
            };    
        };
        
        
   
return 0;

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// nice implementation of linked lists


#include <cstddef>

using namespace std;

class Node {
    public:
        int data;
    Node * next;
};

int main() {
    Node * head = NULL;
    Node * second = NULL;
    Node * third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second-> data = 2;
    second-> next = third;

    third-> data = 3;
    third-> next = NULL;
}










///////////////////////////////////////////////////////////////////////////////


// Iterative C++ program to find length
// or count of nodes in a linked list

using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);    //??????????
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Counts no. of nodes in linked list */
int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Use push() to construct below list
    1->2->1->3->1 */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    // Function call
    cout << "count of nodes is " << getCount(head);
    return 0;
}
 
































