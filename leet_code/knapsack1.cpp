#include <iostream>
#include <map>
using namespace std;


int items [10000][2];
int current_weight = 0;


// finding max score of items where , items weights < max_weight 
int get_max_collection( int no_of_items , int max_weight, int last_item_index , int current_weight)
{

    if (last_item_index==no_of_items)
        return 0;


    int max_result =0;
    int current_score =0 ;
    for (int i=0 ; i <= no_of_items ; i++ )
    {
        if (current_weight<= max_weight)
        {
            current_weight += items[i][0];
            current_score += items[i][1];

        }
    }






    return max_result;
}





