
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

You are climbing a staircase. It takes nn steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example

Let's say n=4n=4. The possible ways to climb to the top are:

    1+1+1+11+1+1+1
    1+1+21+1+2
    1+2+11+2+1
    2+1+12+1+1
    2+22+2

So, there are 5 ways to reach the top when n=4n=4.
Steps to Solve the Problem Using Dynamic Programming

    Define the State:
        Let dp[i] represent the number of distinct ways to reach step ii.

    Base Cases:
        dp[0] = 1 (There is one way to stay at the ground step, by doing nothing)
        dp[1] = 1 (There is one way to reach the first step, by taking a single step)

    Recurrence Relation:
        To reach step ii, you can either come from step i−1i−1 by taking a single step, or from step i−2i−2 by taking two steps.
        Therefore:
        dp[i]=dp[i−1]+dp[i−2]
        dp[i]=dp[i−1]+dp[i−2]

"""

