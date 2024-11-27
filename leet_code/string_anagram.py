

"""
Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? 
How would you adapt your solution to such a case?
    
    
    

    Returns:
        _type_: _description_
"""





class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # you van reorder alphapatically , and check if s==t
        # or for each character in s check if exist in t and delete it

        # sorted complexity :
        #   Time Complexity: O(nlog⁡n)O(nlogn), where nn is the length of the list.
        #   Space Complexity: O(n)O(n), for temporary storage during sorting.

        # if len(s)!=len(t):
        #     return False

        # ordered_s = sorted(s)
        # ordered_t = sorted(t)
        # return ordered_s==ordered_t



        # best solution
        #make a map for a string then compare the other string with map

        # first exclude non equal strings
        if len(s)!=len(t):
            return False
        map={}
        for i in s:
            if i not in map.keys():
                map[i]=1
            else:
                map[i]=map[i]+1

        for i in t:
            # check if char in map ( note) the other condition to account for when char exist but = 0
            if i in map.keys() and map[i]!=0:
                map[i]=map[i]-1

        print(map)
        return sum(map.values())==0


        # another solution (bad , the above is better)
        # if len(s)!=len(t):
        #     return False
        # for i in s :
        #     if i in t:
        #         # remove this char from the string (replace only one occurance)
        #         t=t.replace(i,'',1)
        # print(t)
        # return len(t)==0