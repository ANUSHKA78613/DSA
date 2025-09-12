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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(!root->left && !root->right) return 0;
        int l = 0, r = 0;
        if(root->left) 
              l = 1 + solve(root->left);
        if(root->right) 
              r = 1+ solve(root->right);
        ans = max(ans,l+r);
    return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans == INT_MIN ? 0 : ans;
    }
};