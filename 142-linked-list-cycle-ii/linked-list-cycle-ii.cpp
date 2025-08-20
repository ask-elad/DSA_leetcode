/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *tort = head;
        ListNode *hare = head;

        if (hare == NULL || hare->next == NULL) {
            return NULL;
        }
        while (hare != NULL && hare->next != NULL) { 
            hare = hare->next->next;
            tort = tort->next;
            if (hare == tort) {
                tort = head;
                while (hare != tort) {
                    tort = tort->next;
                    hare = hare->next;   
                }
                return hare;
            }
        }
        return NULL;  
    }
};
