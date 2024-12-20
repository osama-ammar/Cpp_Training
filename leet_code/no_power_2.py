
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

        
        #using bits count method  
        #All power of two numbers has only a one-bit set. So count the no. of set bits and if you get 1 then the number is power of 2. 
        count = 0
        """ 
        # When you do n & 1, you are comparing the bits of the number n with the bits of the number 1. In binary, the number 1 is written as 0001.:
        # compares each bit of its operands. If both bits are 1, it results in 1; otherwise, it results in 0.
        Since 1 in binary is 0001, it means that n & 1 will only check the very last bit of n. Here's why:
                If the last bit of n is 1, then n & 1 will be 1.
                If the last bit of n is 0, then n & 1 will be 0.
                
        n & 1 checks the last block of n.
        If n & 1 is 1, it means the last block is 1.
        If n & 1 is 0, it means the last block is 0.
        
        In binary terms, n & 1 isolates the LSB of n. For example:

            8 (1000 in binary) → 8 & 1 = 0
            9 (1001 in binary) → 9 & 1 = 1
            
        # effect of n>>1    
        if n = 8   binary:[1000]
        n >> 1 ----> n=4  binary:[0100]
        n >> 1 ----> n=2  binary:[0010]
        and so on
        """
        
        
        while n > 0:      
            # mean : for each bit in bits representation of n ---> if this bit ==1 count++ ---> move to the next bit  ---> for number is power of 2 :: they should have only 1 in their bits representation ex(0010000)
            # if count is more than one ---> n is not number is power of 2
            if n & 1 == 1:
                count = count + 1
                
            n = n >> 1 ## Shift bits to the right by 1 position  (1000 ----> 0100)---> meaning dividing n by 2 in bitwise level
            print(n)

        if count == 1:
            return True
        return False

a=Solution()
print(a.isPowerOfTwo(15,30))