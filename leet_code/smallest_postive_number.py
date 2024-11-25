"""
This is a demo task.

Write a function:

    def solution(A)

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

"""

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # Implement your solution here
    max_item = max(A)
    min_item = min(A)
    #base case
    if min_item>1 :
        return min_item-1

    if max_item<1 :
        return 1
    
    # for each item in array check
    #   if min >1 --->sol=1
    #   if min++ in list : not in list return it
    for i in range(min_item,max_item+2):
        if i in A:
            pass
        else: 
            return i

