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
    int answer = INT_MIN;

    int rec(TreeNode* root){
        if(root == nullptr) return 0;

        int lSum = 0;
        int rSum = 0;

        if(root->left) lSum = rec(root->left);
        if(root->right) rSum = rec(root->right);

        int sum = root->val;
        if(lSum > 0) sum += lSum;
        if(rSum > 0) sum += rSum;

        answer = max(answer, sum);

        return root->val + max(0, max(lSum, rSum));
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        rec(root);
        return answer;
    }
};