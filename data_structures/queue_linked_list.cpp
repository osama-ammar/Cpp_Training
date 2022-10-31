
// implementing queue using linked list for more performance in very large queue sizes
// the front here looks like the head

#include <iostream>
#include <string>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL; // global scope
node *rear = NULL;  // global scope

void enqueue(int value);
void dequeue();
void display();
int peek();

int main()
{

    int lis[] = {1, 2, 3, 4, 5};
    for (int i : lis)
    {
        enqueue(i);
    }

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();

    peek();

    return 0;
}

void enqueue(int value)
{
    node *new_node = new node; // a pointer of type node that points to a place in the memory that has this allocated empty node
    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL)
    {
        rear = new_node;
        front = new_node;
        cout << "adding first node..." << endl;
    }
    else
    {

        rear->next = new_node; // rear
        rear = new_node;

        cout << "adding a new node..." << endl;
    }
}

void dequeue()
{
    if (rear == NULL)
    {
        cout << "nothing to remove" << endl;
    }
    else if (rear == front) // only one item in the queue
    {
        node *ptr = front; // a pointer used to point to the node we want to remove ... so that we can remove it and avoid memory leak
        front = rear = NULL;
        delete (ptr);
    }
    else
    { // there are many items
        node *ptr = front;
        front = front->next; //
        delete (ptr);
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "nothing to DISPLAY" << endl;
    }
    else
    {
        node *ptr = front;
        while (ptr != NULL)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next; //
        }
    }
    cout << endl;
}

int peek()
{
    if (front == NULL)
    {
        cout << "nothing to DISPLAY" << endl;
        return -1;
    }
    else
    {
        return front->data;
    }
}
