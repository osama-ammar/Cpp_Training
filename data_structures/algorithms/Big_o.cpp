

/*

Asymptotic notations are the mathematical notations used to describe the running time of an algorithm when the input tends towards a particular value or a limiting value

There are mainly three asymptotic notations:

    Big-O notation : Big-O notation represents the upper bound of the running time of an algorithm. Thus, it gives the worst-case complexity of an algorithm.

    Omega notation : Omega notation represents the lower bound of the running time of an algorithm. Thus, it provides the best case complexity of an algorithm

    Theta notation : Theta notation encloses the function from above and below. Since it represents the upper and the lower bound of the running time of an algorithm,
                    it is used for analyzing the average-case complexity of an algorithm.


    ?? The master theorem is used in calculating the time complexity of recurrence relations (divide and conquer algorithms) in a simple and quick way.
    T(n) = aT(n/b) + f(n),
    where,
    n = size of input
    a = number of subproblems in the recursion
    n/b = size of each subproblem. All subproblems are assumed 
        to have the same size.
    f(n) = cost of the work done outside the recursive call, 
        which includes the cost of dividing the problem and
        cost of merging the solutions

    Here, a ≥ 1 and b > 1 are constants, and f(n) is an asymptotically positive function.


    example: consider you have an array of 12 elements and you want to sort it ....and you will use devide and conquer algorithm to do this
                we will divide the arry into 2 arrays and divide each subarray will although be divided into 2 subarrays and so on 


    let's use this formula
    T(n) = aT(n/b) + f(n),
    where,
    n = size of input
    a = number of subproblems in the recursion
    n/b = size of each subproblem. All subproblems are assumed to have the same size.
    f(n) = cost of the work done outside the recursive call, which includes the cost of dividing the problem and cost of merging the solutions


*/







