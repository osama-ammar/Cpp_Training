
"""

347. Top K Frequent Elements
===============================
- related ~ to K closese points
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 



"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # make a dict 
        # fill it ..if item exists (item:occurance)
        # retun highest occurence

        # base case (( very tricky point))
        if len(nums)==k:
            return nums

        items_dict={}
        max_items=[]
        for i in nums :
            if i not in items_dict.keys():
                items_dict[i]=1
            else:
                 items_dict[i]+=1

        # sort values
        dict_values = items_dict.values()
        max_values = sorted(dict_values,reverse=True)

        print(max_values)
        #find associated keys
        for key , val in items_dict.items(): # order of this line and next line is very important (reversing them causes error)
            for i in max_values[0:k]:
                if i==val:
                    max_items.append(key)
                    break

        return max_items
        
