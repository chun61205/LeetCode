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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int flag = 0;
        ListNode *prev = NULL, *returnList = l1;
        while(l1 != NULL && l2 != NULL){
            prev = l1;
            int result = l1->val + l2->val + flag;
            if(result >= 10){
                flag = 1;
                l1->val = result - 10;
            }
            else{
                flag = 0;
                l1->val = result;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 != NULL){
            prev->next = l2;
            while(l2 != NULL){
                prev = l2;
                int result = l2->val + flag;
                if(result >= 10){
                    l2->val = 0;
                    flag = 1;
                }
                else{
                    l2->val = result;
                    flag = 0;
                }
                l2 = l2->next;
            }
            
        }
        else if(l2 == NULL && l1 != NULL){
            while(l1 != NULL){
                prev = l1;
                int result = l1->val + flag;
                if(result >= 10){
                    l1->val = 0;
                    flag = 1;
                }
                else{
                    l1->val = result;
                    flag = 0;
                }
                l1 = l1->next;
            }
        }
        if(flag == 1)
            prev -> next = new ListNode(1);
        return returnList;
    }
};