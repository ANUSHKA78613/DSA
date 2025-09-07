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
TreeNode* solve(TreeNode* root,TreeNode  *i){
            if(!root)return i;
            if(i->val < root->val){
                root->left = solve(root->left,i);
            }
            else{
                root->right = solve(root->right,i);
            }
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1;i<preorder.size();i++){
            TreeNode *temp = new TreeNode(preorder[i]);
         solve(root,temp);
        }
       return root;
    }
};