
#include <iostream>
#include <string>

/*
Binary search tree : AN EFFECTIVE DATASTRUCTURE FOR search

                    - composed of nodes each node not contain more than 2 sons
                    - the value in Rt son is greater than parent node
                    - the value in Lt son is less than parent node
                    - search time complexity - log2 (n)
                    -each value in BST is unique ( no repeated nodes exist)


                Disadvantages : when tree is unbalanced , this occuers when adding
                                nodes occuers in fixed direction () . thus converting the tree into linked list


*/

class Node
{
public:
    int value;
    Node *right;
    Node *left;

    // constructor
    Node()
    {
        this->value = 0;
        this->right = nullptr;
        this->left = nullptr;
    }

    // parameterized constructor
    Node(int value, Node *right, Node *left)
    {
        this->value = value;
        this->right = right;
        this->left = left;
    }
};

// class composition ???????

class BST
{
private:
    Node *root;

public:
    bool value_exist(int value)
    {
        Node *p = root;
        while (p != nullptr)
        {
            if (p->value == value)
                return true;

            if (value > p->value)
                p == p->right;
            else
                p == p->left;
        }
        return false;
    }

    void add_value(int value)
    {
        if (value_exist(value))
            return;

        // creating a new node
        Node *n = new Node(value, nullptr, nullptr);

        // if tree is empty
        if (root == nullptr)
        {
            root = n;
            return;
        }

        // otherwise you can add a new value but let's locate the proper position to add it
        // make a parser pointer
        Node *p = root;
        while (true)
        {
            if (value > p->value)
            {
                if (p->right == nullptr)
                    break;
                p = p->right;
            }
            else
            {
                if (p->right == nullptr)
                    break;
                p = p->left;
            }
        }

        // putting our new node in the proper place
        if (value > p->value)
        {
            p->right = n;
        }
        else
        {
            p->left = n;
        }
        std::cout<< " a new value is added"<< std::endl;
    }

    // deep first search .. ( based on recursions)
    void DFS(Node *p)
    {

        if (p == nullptr)
            return;
        std::cout << p->value << "-->";

        DFS(p->left);
        DFS(p->right);
    }

    void print()
    {
        DFS(root);
    }
};

int main()
{

    BST tree;
    tree.add_value(10);
    tree.add_value(5);
    tree.add_value(15);
    tree.add_value(7);
    tree.add_value(27);
    tree.add_value(5);
    tree.add_value(44);

    tree.print();

    return 0;
}
