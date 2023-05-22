
#include <iostream>
#include <string>
#include <queue>
#include "DFS.cpp"

using namespace std;


/*
    - BSH algorithm depends on queue

    the steps of Bread first search is :
                        1- put node value in a queu front and print it
                        2- put its right then left 
                        3- pop this node from front and move to next value (queue front or previous node right )
                        4- repeat the previous steps




*/


//  breadest first search algorithm (push,print,add right and left, pop)depends on queue 
void BFS (Node * n)
{
    queue<Node*> my_queue;
    my_queue.push(n);

    while (!my_queue.empty())
    {
        cout<<my_queue.front()->value<<endl;

        if (my_queue.front()->right!=nullptr)
            my_queue.push(my_queue.front()->right);

        if (my_queue.front()->left!=nullptr)            
            my_queue.push(my_queue.front()->left);

        my_queue.pop();
    }

    

}