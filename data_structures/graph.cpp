

#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
Graph : non linear datastructure composed of :
        Nodes : (connection) 
        Edges : (direction ,  wight)


    can be represented by :

            Adjacency list : memory efficient
                            - collection of linked lists


            Adjacency matrix : less memory efficient
                            -  matrix of 0  and 1 between every node in the graph and the other node


*/

struct graph {
    const int nodes = 5;
    const int edges =7;
    //making a 2d vector that has (nodes+1) rows
    //represent graph as adjacency matrix
    vector<int> graph;
};


int main()
{
    const int nodes = 5;
    const int edges =7;
    //making a 2d vector that has (nodes+1) rows
    //represent graph as adjacency matrix
    vector<int> graph[nodes+1];


    for(int i = 0; i < edges; i++)
    {
        int node1 , node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);    
    }

    //traversing nodes into graph
    for (int i = 1; i <= nodes;i++)
    {
        cout << i << "===>> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] <<endl;
        }
    }

    //traversing the graph









    return 0;
}







