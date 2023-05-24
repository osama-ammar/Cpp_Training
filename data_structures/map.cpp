// looks like dictionary in C++

#include <iostream>
#include <string>
#include <map>
using namespace std;


void view_map (map<int, string> my_map)
{

    map<int,string>::iterator it ;

    for (it = my_map.begin(); it != my_map.end(); it++) {
        cout<<it->first<<": "<< it->second <<endl;
    }
}



int main ()
{
    map<int,string> my_map;

    // inserting values to the map 
    my_map.insert(pair<int,string> (112,"osama sayed"));
    my_map.insert(pair<int,string> (312,"malek sayed"));
    // or
    my_map[3143]="hosssm kindle";
    my_map[5543]="kiodd kddsle";

    view_map(my_map);

    //erase a specefic key
    my_map.erase(312);

    //erase a specefic range from map begin to specefic key
    my_map.erase(my_map.begin(),my_map.find(3143));

    //creating a new map from last map
    map<int,string> my_sec_map(my_map.begin(),my_map.end());

    return 0;
}

