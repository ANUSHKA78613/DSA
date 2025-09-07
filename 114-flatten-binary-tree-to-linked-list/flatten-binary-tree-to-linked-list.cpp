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
    void preorder(TreeNode* root,vector<int>& in){
        if(root == NULL) return;
      in.push_back(root->val);
      preorder(root->left,in);
      preorder(root->right,in);

    }
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<int> in;
        preorder(root, in);

        TreeNode* curr = root;
        for (int i = 1; i < in.size(); i++) {
            curr->left = NULL;                      // flatten left
            curr->right = new TreeNode(in[i]);      // link new node
            curr = curr->right;                     // move forward
        }
    }
};
