/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode *temp = head;
//         unordered_map<ListNode*, int> nodeMap;  

//         while (temp != nullptr) {
//             if (nodeMap.find(temp) != nodeMap.end()) {
//                 return true;
//             }
//             nodeMap[temp] = 1;
//             temp = temp->next;  
//         }
//     return false;
//     }
// };
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *tort = head;
            ListNode *hare = head;

            if (hare == NULL || hare->next == NULL) {
                return false;
            }
            while (hare != NULL && hare->next != NULL) { 
                hare = hare->next->next;
                tort = tort->next;
                if (hare == tort) {
                    return true;
                }
            }
            return false;
        }
    };
