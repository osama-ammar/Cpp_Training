import sys
import threading
import time
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)


def time_decorator(func):
    def wrapper(*args,**kwargs):
        start_time=time.time()
        result=func(*args ,**kwargs)
        end_time=time.time()
        print(f"ececution time : {end_time-start_time}")
        return result
    return wrapper




#@time_decorator
def fabonanci(n):
    if n==1 : return 1
    if n==2 : return 1
    
    else :
        result = fabonanci(n-1) + fabonanci(n-2)
        return result
    










#@time_decorator
def fabonanci_dynamic(n,memory={}):
    
    #base case
    if n==1 or n==2: return 1

    # check in memory
    if n in memory:
        return memory[n]
    
    else :
        value1=fabonanci_dynamic(n-1,memory)
        value2=fabonanci_dynamic(n-2,memory)

        result = value1 +value2
        
        #save in memory
        memory[n]=result
        
        return result
    

# start_time=time.time()
# print(fabonanci(37))
# print(f"time : {time.time()-start_time}")


start_time=time.time()
print(fabonanci_dynamic(37,memory={}))
print(f"time : {time.time()-start_time}")