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

        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;

        while(list1 != nullptr && list2 != nullptr){

            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1 != nullptr){
            temp->next = list1;
        }

        if(list2 != nullptr){
            temp->next = list2;
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();
        if(k == 0) return NULL;

        ListNode* ans = lists[0];

        for(int i = 1; i < k; i++){
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};