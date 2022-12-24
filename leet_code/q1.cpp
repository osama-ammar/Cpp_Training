/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}                                    ????????????
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// I will merge these lists then sort them


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}   ;                                 //????????????
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head1=list1;
        ListNode* checker1=head1;

        ListNode* head2=list2;
        while (checker1!=NULL){
            checker1=checker1->next;
        }
        //checker1 is now at the endof list1....lets connect list1 to list2
        checker1->next=head2;

        ListNode* stop_checker=head1;
        ListNode* min_checker=head1;

        while (min_checker->next!=NULL){
            if (min_checker->val<stop_checker->val) {
                //making minimum the first in the linked list
                min_checker->next=stop_checker;
                min_checker=min_checker->next;
            }

        }
        return min_checker;

    }
};


















int main(){

    Solution member;
    ans=member.mergeTwoLists(ListNode* list1, ListNode* list2);


    return 0;
}