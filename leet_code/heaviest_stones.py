

"""
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

"""





"""
Hints
======

# if no stones return 0
# list.pop(index) -------- list.remove(value)
# var1= var2 ------> not copy ( they both refer to the same object)
# var1= var2.copy() ------>  copy 
# since the list will be decresing I'DON'T CARE ABOUT ORDER



"""





from types import List

# complex solution (better)
# find the 2 heaviest stones
# compare them --> if == -->elimnate them from the arry
#                   ---> elimnate the smaller , bigger minus smaller 


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        if len(stones)==1:
            return stones[0]

        while len(stones) > 1:
            first_stone = max(stones)
            stones.remove(first_stone)
            second_stone = max(stones)
            stones.remove(second_stone)
            if first_stone != second_stone:  
                new_weight = abs(first_stone - second_stone)
                stones.append(new_weight)
                continue

            # to account for case like [1,1] are the remainnig
            if len(stones)==0:  
                return 0

        return stones[0]




#simpler
    def lastStoneWeight(self, stones: List[int]) -> int:

        while len(stones)>2:
            stones.sort()
            large_stone = stones[-1]
            small_stone = stones[-2]

            stones=stones[0:-2]
            stones.append(abs(large_stone-small_stone))
            print(stones)
        if len(stones)==2:
            return abs(stones[0]-stones[1])

        return stones[0]





