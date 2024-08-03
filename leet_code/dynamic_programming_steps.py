
"""
General steps and questions you should ask yourself:


- what is the basic case
- what argum ents do you need in the next call
-
-
-
-
-
-
-

Problem Statement

You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
Example

Let's say n=4. The possible ways to climb to the top are:

    1+1+1+1
    1+1+2
    1+2+1
    2+1+1
    2+2

So, there are 5 ways to reach the top when n=4.
Steps to Solve the Problem Using Dynamic Programming

    Define the State:
        Let dp[i] represent the number of distinct ways to reach step i.

    Base Cases:
        dp[0] = 1 (There is one way to stay at the ground step, by doing nothing)
        dp[1] = 1 (There is one way to reach the first step, by taking a single step)

    Recurrence Relation:
        To reach step i, you can either come from step i−1 by taking a single step, or from step i−2 by taking two steps.
        Therefore:
        dp[i]=dp[i−1]+dp[i−2]
        dp[i]=dp[i−1]+dp[i−2]

"""
ways=0
def distincit_ways(no_of_stairs):
    
    # base case
    if no_of_stairs==0 or no_of_stairs ==1:
        return 1
    
    # recurrence : to reach n stair is by from (1 stair before  or(+) 2 stairs before it) it(or ======>>> +   || and======>>> x  )
    ways = distincit_ways(no_of_stairs-1) + distincit_ways(no_of_stairs-2)
        
    #print(f"no of distincit ways = {ways}")
    return ways

ways=0
mem={}
def distincit_ways_with_mem(no_of_stairs):
    
    #getting from casch
    if no_of_stairs in mem.keys():
        return mem[no_of_stairs]
    
    # base case
    if no_of_stairs==0 or no_of_stairs ==1:
        return 1
    
    # recurrence : to reach n stair is by from (1 stair before  or(+) 2 stairs before it) it(or ======>>> +   || and======>>> x  )
    ways = distincit_ways(no_of_stairs-1) + distincit_ways(no_of_stairs-2)
    mem[no_of_stairs]= ways
        
    #print(f"no of distincit ways = {ways}")
    return ways
# print(distincit_ways_with_mem(3))
# print(distincit_ways_with_mem(4))
# print(distincit_ways_with_mem(5))




#=========================================================================================
"""
Problem Statement

Given an array of coins of different denominations and a total amount of money, determine the fewest number
of coins needed to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.
Example

Let's say we have the following coins: [1, 2, 5], and the total amount is 11.

The possible ways to make up the amount 11 are:

    11 = 5 + 5 + 1 (3 coins)============ [min]
    11 = 5 + 2 + 2 + 2 (4 coins)
    11 = 2 + 2 + 2 + 2 + 2 + 1 (6 coins)
    .......................

"""
#
coins_array=[]
possible_solutions=[]
summation =0 
def min_no_of_coins(required_amount):
    # base case : no coins=0 ----> min= 0 
    if required_amount==0:
        return 0
    
    # stop if summation == required amount
    for i in coins_array:
        summation+=i
        if summation==required_amount :
            possible_solutions.append(summation)
            return summation
        
        











