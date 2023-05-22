
#include <iostream>
#include <string>
#include <array>
/*
Binary search tree (set in stl) : AN EFFECTIVE DATASTRUCTURE FOR search

                    - composed of nodes each node not contain more than 2 sons
                    - the value in Rt son is greater than parent node
                    - the value in Lt son is less than parent node
                    - search time complexity - log2 (n)
                    -each value in BST is unique ( no repeated nodes exist)


                Disadvantages : when tree is unbalanced , this occuers when adding
                                nodes occuers in fixed direction () . thus converting the tree into linked list


                -if we are going to delete a node that have 2 sons : the best value to put in its place is (اكبر صغير او اصغر كبير)


                -DFS  algorithm depends on recursion


*/

struct node_info {
    Node*  node;
    Node*  parent;
    std::string direction;

};



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
                
                p = p->right;
                    break;
            }
            else
            {
                if (p->left == nullptr)
                
                p = p->left;
                    break;
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

    // return a pointer that points to the required value in the tree
    Node* move_to_value(int value)
    {
        if (!value_exist(value))
            {
            std::cout<<"value doesn't in the tree"<<std::endl;
            return;
            }

        Node* p = root;

        
    }



    // (DFS)  deep first search Algorithm .. ( based on recursions)
    void DFS(Node *p)
    {

        if (p == nullptr)
            return;
        std::cout << p->value << "-->";

        DFS(p->left);
        DFS(p->right);
    }



    // function overloading ?
    // search for a value and return a pointer that points to it and another pointer points to its parent
    node_info  find_value(Node * p,int value,std::string direction,Node*  parent)
    {
        //what about this , to avoid redefining parent in every call

        static node_info node_struct;

        //
        if (p == nullptr)
        {
            std::cout << "empty root" << std::endl;
            return;
        }

        if (p->value == value)
        {
            std::cout<<"value found"<<std::endl;
            node_struct.node= p;
            node_struct.parent=parent;
            node_struct.direction= direction;
            return node_struct;
        }

        if (value > p->value)
        {
            parent=p;
            p=p->right;
            direction="right";
        }
        else
        { 
            parent=p;
            p=p->left;
            direction="left";
        }
        find_value(p,value,direction,parent);

    }

    void print()
    {
        DFS(root);
    }



    /* when deleting we have here 5 cases:
    - the node you want to delete doesn't exist : do nothing 
    - the node has no sons : make her parent points to nullptr
    - the node has only right son : make her parent points this  son
    - the node has only left son : make her parent points this  son
    - the node has right and left son : put a new value inside this node (from right left direction or vice verse)
    
    */
    void delete_node (int value){

        if (!value_exist(value))
            return;

        Node* p ;
        static Node* parent;
        node_info node_struct;
        static std::string direction;

        //this struct carries the node, its parent , and we although have its direction
        node_struct= find_value(root,value,direction,parent);
        



        if (p->right==nullptr && p->left==nullptr)
        {
            node_struct.parent=nullptr;
        }


        if (p->right!=nullptr)
        {
            node_struct.parent->right=p->right;
        }


        if (p->left!=nullptr )
        {
            node_struct.parent->left=p->left;
        }


        if (p->right!=nullptr && p->left!=nullptr)
        {
            //the smallest big
            node_struct.node->value=p->right->left->value;
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
    tree.add_value(12);
    tree.add_value(44);

    //tree.print();

    return 0;
}
