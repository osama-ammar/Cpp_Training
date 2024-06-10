
"""
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is

hi​.

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone

N:

    If the frog is currently on Stone 

i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi​−hj​∣ is incurred, where

    j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone
N.
        _type_: _description_
"""




def brute_frog(current_element_id=0 ):
    pass
    
    
    
    
def recursion_frog(current_element_id=0 ):
    pass
    

number_of_elements = 0
elements_list =[]
computations = []
def dynamic_frog(current_element_id=0 ):
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
    
    ans_with_cost1 = dynamic_frog(current_element_id+1)
    ans_with_cost2 = dynamic_frog(current_element_id+2)
    
    ans=min(ans_with_cost1 +cost1 ,ans_with_cost2 + cost2)
    print(ans)
    computations[current_element_id]=ans
    
    return ans