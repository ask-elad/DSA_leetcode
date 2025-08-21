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
    bool isPalindrome(ListNode* head) {

        stack<ListNode*> st;   
        ListNode *temp = head;

        // push all nodes
        while (temp != NULL) {
            st.push(temp);      
            temp = temp->next;
        }

        temp = head;

        while (!st.empty()) {
            if (temp->val != st.top()->val) {   
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};
