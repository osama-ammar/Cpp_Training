#include <iostream>
using namespace std;
/*
- what is the base case .... simplest case (here ..when no_of_days=0)
- what info do you need as function inputs when you make a transition
- make recursion then momoization


*/

int vaccation[100000][3];
int no_of_days;
int max_path(int day , int prev_activity_index) {

        //base case
        if (no_of_days == day)
            return 0; 

        // transition
        int max_result=0;
        for(int i=0 ; i<=2 ; i++)
        {
            if(prev_activity_index!=i)
            {

                int score = max_path(day+1 , i) + vaccation[day][i];
                max_result = max(score,max_result);
            }
                //max_result= max(max_path(day+1,i),max_result) + vaccation[day][i] ;
        }

        return max_result;
    
}

int main()
{
    cin>>no_of_days;
    for(int i = 0 ; i<no_of_days ; i++)
    {
        for(int j=0 ; j<=2 ; j++)
            cin>>vaccation[i][j];
    }

    int result1 = max_path(0,0);
    int result2 = max_path(0,1);
    int result3 = max_path(0,2);

    cout<<max(result3,max(result1,result2));

    
}











