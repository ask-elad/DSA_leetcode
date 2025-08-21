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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* odd = a;
        ListNode* even = b;
        ListNode* evenHead = b; 

        while(a != NULL && a->next != NULL && b != NULL && b->next != NULL){

            odd->next = a->next->next;
            odd = odd->next;
            a = odd;   

            even->next = b->next->next;
            even = even->next;
            b = even;  
        }

        odd->next = evenHead;   
        return head;           
    }
};
