
#include <iostream>

/*


You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.


Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:
Input: list1 = [], list2 = []
Output: []


Example 3:
Input: list1 = [], list2 = [0]
Output: [0]


Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.



*/


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};






class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // put pointer_a in a list (strt small)
    // put *pointer_max in the other list
    // starting from pointer a (which lies in smaller head) check which is
    // smaller [pointer_max or pinter_a.next] if pointer_max is smaller (a
    // points to b place and ake p on 1st a next) and so on
    auto *pointer_min = list1;
    auto *pointer_max = list2;
    auto *list_temp = list1;

    // in case of one list is empty
    if (list1 == nullptr)
      return list2;

    if (list2 == nullptr)
      return list1;


    // ensure starting from the min val
    if (list1->val > list2->val) {
      pointer_min = list2;
      pointer_max = list1;
      list_temp = list2;
    }

    while (pointer_min->next != nullptr) {
      std::cout << pointer_min->next->val << std::endl;
      if (pointer_min->next->val > pointer_max->val) {
        auto *temp = pointer_max;
        pointer_max = pointer_min->next;
        pointer_min->next = temp;
        pointer_min = pointer_min->next;
      } else {
        pointer_min = pointer_min->next;
      }

      // std::cout << pointer_min->val << std::endl;
    }

    // in case of we finsihed and still we have some items in on of the lists
    pointer_min->next = pointer_max;

    return list_temp;
  }
};