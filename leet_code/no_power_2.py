
"""

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?

"""


import math
class Solution(object):
    @staticmethod
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # using log2 method ---.not working ????
        # # given a**x =n --> log-a(n) =x
        # if n<0:
        #     return False

        # result = math.log(n,2) 

        # if result%1==0:
        #     return True
        # else:
        #     return False
        
        
        #using bits count method  
        #All power of two numbers has only a one-bit set. So count the no. of set bits and if you get 1 then the number is power of 2. 
        count = 0
        while n > 0:
            # compares each bit of its operands. If both bits are 1, it results in 1; otherwise, it results in 0.
            # mean : for each bit in bits representation of n ---> if this bit ==1 count++ ---> move to the next bit  ---> for number is power of 2 :: they should have only 1 in their bits representation ex(0010000)
            # if count is more than one ---> n is not number is power of 2
            if n & 1 == 1:
                count = count + 1
            n = n >> 1

        if count == 1:
            return True
        return False

a=Solution()
a.isPowerOfTwo(15)