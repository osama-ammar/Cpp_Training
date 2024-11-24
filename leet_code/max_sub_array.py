


"""
Given an integer array nums, find the
subarray
with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

 

Follow up: If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.

"""











# Note : here , it's not about finding the subarray but finding the max sum

from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Initialize variables to track the max sum and current sum
        max_sum = nums[0]
        current_sum = nums[0]

        # Iterate through the array starting from the second element
        for num in nums[1:]:
            # Decide whether to add the current number to the current sum
            # or start a new subarray
            current_sum = max(num, current_sum + num)

            # Update max_sum if the current_sum is larger
            max_sum = max(max_sum, current_sum)

        return max_sum
 