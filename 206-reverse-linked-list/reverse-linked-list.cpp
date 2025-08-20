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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;   

        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *prev = NULL;

        while (a != NULL) {
            a->next = prev;
            prev = a;
            a = b;
            if (b != NULL) b = b->next;
        }
        return prev;  
    }
};
