#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

/*
Paradigm : way of thinking

Algorithms paradigms : almost any algo can be categorized as 1 or more of 5 paradigms which are :
                1- Brute force : a brute careless guy who brutely try to solve a problem
                                ex (linear search)

                2- Divide and conquer : mostly uses recursion
                                    ex(merge sort)

                3- Back tracking : similar to Brute force but for large problems
                                    search from deep to first
                                    ex (DFS -Deep first search)

                4- Greedy : reaching the optimum solution in many stage
                            these stages are ordered by optimum
                            -it suppose a hypothesis and try it ??


                5- Dynamic Programming : optimization technique based on storing past solutions
                                        uses divide and conquer
                                        ex (Faponanci series)


*/

// solving fibonanci problem by recursion
int fib(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    else
        return fib(x - 1) + fib(x - 2);
}

// an array used to store calc of dybmaic programming algotirhm
int fib_arr (int x) {

    const int var =const(x);
    int arr[var];
    arr[0]=0; arr[1]=1;
    for (int i=2; i<=x; i++)
        arr[i]=-1;

    return arr;
}

// using dynamic programming (storing old results to avoid repeating them)
int dynamic_fib(int x , int arr[])
{ 
    //if value is  previously calculated -> use it and don't calculate it again 
    if (arr[x] != -1)
        return arr[x];

    //otherwise ..calculate it and store it
    arr[x] = dynamic_fib(x-1, arr)+dynamic_fib(x-2, arr);
    return arr[x];

}

int main()
{

    int t_start = time(NULL);
    int result = dynamic_fib(var,arr);
    //int result =fib(var);
    int t_end = time(NULL);

    cout <<result<<endl;
    cout << "time consumed = " << t_end - t_start << endl;
    return 0;
}
