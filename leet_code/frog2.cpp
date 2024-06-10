
/*
[https://atcoder.jp/contests/dp/tasks]


*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int get_min_cost(vector<int> arr, int max_steps  ,int current_element = 0 )
{

    if (arr.size()==1)
        return 0;

    if (arr.size()==2)
        return abs(arr[1]-arr[0]);


    
    int initial_cost = -1;
    int min_cost;
    int sum_min_cost;

    vector<int> possible_costs;
    for (int i=1 ; i<arr.size() ; i++)
    {
        int current_cost = abs(arr[current_element]-arr[i]);
        possible_costs.push_back(current_cost);
        for(int & c :possible_costs)
        {
            if (c<initial_cost)
            {
                initial_cost=c;
                min_cost = c;
            }
        }
        current_element++;
        sum_min_cost = min_cost + get_min_cost(arr,max_steps,current_element)
    }



}

int main()
{

}



