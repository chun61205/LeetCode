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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *array[30];
        ListNode *curr = head;
        int size = 0;
        while(curr != NULL){
            array[size] = curr;
            size++;
            curr = curr->next;
        }
        if(size == n)
            head = head->next;
        else{
            array[size - n - 1]->next = array[size - n]->next;
        }
        return head;
    }
};