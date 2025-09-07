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
 void inorder(TreeNode* root, vector<int>& in){
    if(root == NULL) return;
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
    }
    //
     TreeNode* inorder_to_bst(int st, int end, vector<int>& in){
        if(st>end) return NULL;
        int mid = st + (end-st)/2;
       TreeNode* root = new TreeNode(in[mid]);
        root->left = inorder_to_bst(st,mid-1,in);
        root->right = inorder_to_bst(mid+1,end,in);
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>in;
        inorder(root,in); 
        int n = in.size()-1;
         return inorder_to_bst(0,n,in);
    }
};