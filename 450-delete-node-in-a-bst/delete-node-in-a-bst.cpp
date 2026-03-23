/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        else{
            //for no chidls
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            //for 1 child
            else if(root->left == nullptr){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == nullptr){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            //for 2 children
            else{
                TreeNode* temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
    }

    TreeNode* FindMin(TreeNode* root){
        while(root->left != nullptr) root = root->left;
        return root;
    }
};