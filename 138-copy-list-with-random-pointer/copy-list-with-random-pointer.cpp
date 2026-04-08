/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;
        Node* temp = head;

        while(temp != NULL){
            Node* nxt = temp->next;

            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nxt;

            temp = nxt;
        }

        temp = head;
        
        while(temp != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        temp = head;
        Node* dummy = new Node(0);
        Node* res = dummy;

        while(temp != NULL){ 
            res->next = temp->next;
            temp->next = temp->next->next;

            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};