// it's a data structure looks like that exists in python and similar to tree in c+

#include <iostream>
#include <string>
#include <set>
using namespace std;

/*
    example stl container for BST

*/





void view_set(set<int> my_set)
{
    set<int>::iterator it;
    for (it = my_set.begin(); it != my_set.end(); it++)
        cout << *it << endl;
}

int main()
{
    set<int> test_set;
    for (int i = 0; i < 30 ; i += 5)
        test_set.insert(i);
    
    view_set(test_set);
    test_set.find(15);


    return 0;
}
