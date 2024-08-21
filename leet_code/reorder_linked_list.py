
"""
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]


Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]


Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

"""






# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        # make a dictionary or it can be a list and save each item in linked list in it 
        # loop through this dict or list and - in a new list - put the items in the required form 1st list[i=0] , 2nd list[n-i] , i++ and so on  
        # add a guard when you reach last node (if current==None :)
        #  time complexity = o(n) , memory complexity= o(n)
        
        n=0
        list_dict = {}
        current = head
        while True :
            list_dict[n]=current.val
            current = current.next
            if current==None  : 
                break
            n+=1
            if current.next==None  : 
                list_dict[n]=current.val
                break


        print(list_dict)

        temp=head    
        for i in range(n):

            if temp==None : 
                break

            temp.val = list_dict[i]
            temp=temp.next

            if temp==None : 
                break
                
            temp.val = list_dict[n-i]

            temp=temp.next

        return temp
    
    
# TODO :
# try to enhance result