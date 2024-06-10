'''
Problem Statement
[https://atcoder.jp/contests/dp/tasks]

There are
N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is

hi​.

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone

N:

    If the frog is currently on Stone 

i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi​−hj​∣ is incurred, where

    j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone

N.
Constraints

    All values in input are integers.

2≤N≤105
1≤hi​≤104
'''






import sys
import threading

sys.setrecursionlimit(10**9)
threading.stack_size(10**8)

number_of_elements = 0
elements_list =[]
computations = []


def dynamic_frog_basic(no_of_elements=len(elements_list) ):
    # for every element find the cost of (element , element+1)  &&  (element , element+1)
    # save each cost difference {(element1,element2) : cost}
    # note : (element1,element2) : cost == (element2,element1) : cost 
    # if an operation exists in the dict ---> don't repeat
    # if reached last element --> stop
    

    # Base case
    if no_of_elements == 2 :
        cost = abs(elements_list[1]- elements_list[0])
        return cost

    if no_of_elements == 1 :
        return 0
    
    # check in memory
    if computations[no_of_elements] != -1 :
        return computations[no_of_elements]
    
    
    cost1 = abs(elements_list[no_of_elements-1] - elements_list[no_of_elements-2])
    cost2 = abs(elements_list[no_of_elements-1] - elements_list[no_of_elements-3])
    
    ans_with_cost1 = dynamic_frog_basic(no_of_elements-1)
    ans_with_cost2 = dynamic_frog_basic(no_of_elements-2)
    
    ans=min(ans_with_cost1 +cost1 ,ans_with_cost2 + cost2)
    print(ans)
    
    computations[no_of_elements]=ans
    
    return ans



def dynamic_frog1(current_element_id=0 ):
    # for every element find the cost of (element , element+1)  &&  (element , element+1)
    # save each cost difference {(element1,element2) : cost}
    # note : (element1,element2) : cost == (element2,element1) : cost 
    # if an operation exists in the dict ---> don't repeat
    # if reached last element --> stop
    

    # Base case
    if current_element_id == number_of_elements-2 :
        cost = abs(elements_list[current_element_id]- elements_list[current_element_id+1])
        return cost

    if current_element_id == number_of_elements-1 :
        return 0
        
    if computations[current_element_id] != -1 :
        return computations[current_element_id]
    
    
    cost1 = abs(elements_list[current_element_id] - elements_list[current_element_id+1])
    cost2 = abs(elements_list[current_element_id] - elements_list[current_element_id+2])
    
    ans_with_cost1 = dynamic_frog1(current_element_id+1)
    ans_with_cost2 = dynamic_frog1(current_element_id+2)
    
    ans=min(ans_with_cost1 +cost1 ,ans_with_cost2 + cost2)
    print(ans)
    computations[current_element_id]=ans
    
    return ans

# if __name__ == "__main__":
#     number_of_elements = int(sys.stdin.readline())
#     elements_list = list(map(int, sys.stdin.readline().split()))
#     computations = [-1]*number_of_elements
    
#     print(dynamic_frog1())


elements_list=[5,13,3,8]
number_of_elements=len(elements_list)
computations = [-1]*number_of_elements
print(dynamic_frog1())

print("______________________")

elements_list=[5,13,3,8]
number_of_elements=len(elements_list)
computations = [-1]*number_of_elements
print(dynamic_frog_basic())
