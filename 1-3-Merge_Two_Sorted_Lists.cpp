// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* headList1 = list1;
        ListNode* headList2 = list2;
        if(list2==NULL){
            return list1;
        }
        else if (list1 == NULL){
            return list2;
        }
        while(list1){
            ListNode* currentList1 = list1;
            list1 = list1->next;    
            if(currentList1->val <= list2->val){
                currentList1->next = list2;
                headList2= currentList1;
                list2=headList2;
                continue;
            }
            while(list2){
                cout << list2->val << " ";
                if(list2->next == 0){
                    list2->next = currentList1;
                    currentList1 -> next = NULL;
                    break;
                }
                if(currentList1->val >= list2->val && currentList1->val < list2->next->val){
                    currentList1->next = list2->next;
                    list2->next = currentList1;
                    break;
                }
                list2 = list2->next;
            }
            list2 = headList2;
        }
        return headList2;
    }
};

// I did not use any other new node for less memory, only linked list 1 nodes to list 2 list. It could be better on time complexity. 