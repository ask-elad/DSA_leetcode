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
    int rec(TreeNode* root, bool toTake, map<pair<TreeNode*, bool>, int>& mp){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr && toTake) return root->val;
        if(root->left == nullptr && root->right == nullptr && !toTake) return 0;

        if(mp.count({root, toTake}) != 0) return mp[{root, toTake}];
        int take =0;
        int notT =0;

        if(toTake) {
            take += root->val;
            if(root->right) take += rec(root->right, false, mp);
            if(root->left) take += rec(root->left, false, mp);
        }

        if(root->right) notT += rec(root->right, true, mp);
        if(root->left) notT += rec(root->left, true, mp);

        return mp[{root, toTake}] = max(take, notT);
    }
    int rob(TreeNode* root) {
        if(root == nullptr)return 0;

        map<pair<TreeNode*, bool>, int>mp;

        int ans = max(rec(root, false, mp), rec(root, true, mp));
        return ans;
    }
};