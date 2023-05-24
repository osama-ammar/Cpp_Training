

#include <iostream>
#include <string>
#include <array>
#include <queue>
#include "BST.h"



// (DFS)  deep first search Algorithm .. ( based on recursions)
void  BST::DFS(Node *p)
{

    if (p == nullptr)
        return;
    std::cout << p->value << "-->";

    DFS(p->left);
    DFS(p->right);
}


//  breadest first search algorithm (push,print,add right and left, pop)depends on queue
void BST::BFS(Node *n)
{
    std::queue<Node *> my_queue;
    my_queue.push(n);

    while (!my_queue.empty())
    {
        std::cout << my_queue.front()->value << std::endl;

        if (my_queue.front()->right != nullptr)
            my_queue.push(my_queue.front()->right);

        if (my_queue.front()->left != nullptr)
            my_queue.push(my_queue.front()->left);

        my_queue.pop();
    }
}



int main()
{

    BST tree;
    tree.add_value(10);
    std::cout<<"a value added to the tree"<<std::endl;
    tree.add_value(15);
    std::cout<<"a value added to the tree"<<std::endl;
    tree.add_value(5);
    std::cout<<"a value added to the tree"<<std::endl;
    tree.add_value(7);
    tree.add_value(27);
    tree.add_value(12);
    tree.add_value(44);

    tree.delete_node(7);

    tree.print();

    return 0;
}
