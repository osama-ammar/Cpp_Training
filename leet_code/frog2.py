
"""
[https://atcoder.jp/contests/dp/tasks]



"""
import sys
import threading

sys.setrecursionlimit(10**9)
threading.stack_size(10**8)

#number_of_elements = 0
max_steps=0
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
        
    # get stored  solutions
    if computations[no_of_elements-1] != -1 :
        return computations[no_of_elements-1]
    
    cost_compare=1e12

    for i in range(1,max_steps+1):
        if i >= no_of_elements:
            break
        cost_n = abs(elements_list[no_of_elements-1] - elements_list[no_of_elements-i-1])
        ans_with_cost_n = dynamic_frog_basic(no_of_elements-i)


        # store solution
        cost_compare=min(ans_with_cost_n + cost_n ,cost_compare) 


    computations[no_of_elements-1]=cost_compare
    
    return cost_compare


if __name__ == "__main__":
    number_of_elements,max_steps = list(map(int, sys.stdin.readline().split()))
    elements_list = list(map(int, sys.stdin.readline().split()))
    computations = [-1]*number_of_elements
    
    print(dynamic_frog_basic(number_of_elements))
