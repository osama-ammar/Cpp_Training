"""

215. Kth Largest Element in an Array
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

    """
# notes : copy_sorted =  sorted(list,reverse=True)
# inplace ---> list.sort()
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # sort the array 
        # find the ith element
        sorted_nums = sorted(nums,reverse=True)
        print(sorted_nums)
        return sorted_nums[k-1]


        # # solving without sort ( but time limit exceeded in large inputs)
        # # find the max item if it's the required index return it 
        # # else remove from the list and find again
        # max_list=[]
        # iterations = len(nums)
        # for j in range(iterations):
        #     max_item=-10000
        #     for i in nums :
        #         if i >= max_item:
        #             max_item = i

        #     max_list.append(max_item)
        #     nums.remove(max_item)
        #     # stop this if we reach the require index
        #     if len(max_list) == k:

        #         return max_list[-1]

