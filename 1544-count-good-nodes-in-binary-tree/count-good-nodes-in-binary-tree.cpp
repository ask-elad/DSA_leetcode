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
    int rec(TreeNode* root, int maxx){
        if(root == nullptr) return 0;

        int ri = 0;
        int le = 0;
        if(root->right){
            if(root->right->val >= maxx){
                ri = 1 + rec(root->right, root->right->val);
            }
            else{
                ri = rec(root->right, maxx);
            }
        }
        if(root->left){
            if(root->left->val >= maxx){
                le = 1 + rec(root->left, root->left->val);
            }
            else{
                le = rec(root->left, maxx);
            }
        }        
        // if(root->val < min) min = root->val;
        // if(root->val > max) max = root->val;

        return ri + le;        
    }
    int goodNodes(TreeNode* root) {
        // right side ke good nodes bata do + left side sub tree ke good nodes bata do
        if(root == nullptr) return 0;
        if(root->right == nullptr && root->left == nullptr) return 1;

        return 1 + rec(root, root->val);
    }
};