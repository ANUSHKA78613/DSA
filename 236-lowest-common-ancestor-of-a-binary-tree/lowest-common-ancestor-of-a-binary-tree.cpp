/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(root == NULL)  return NULL; // case 1: if tree is empty
      if(p == root || q == root ) return root; // case 2 : if any one of them is root
      TreeNode* left = lowestCommonAncestor(root->left,p,q);
      TreeNode* right = lowestCommonAncestor(root->right,p,q);
      if(left && right){ //case 3 :  when both on opposite side
        return root;
      }
      return (left != NULL) ? left : right; // case 4 : on same side
    }
};