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
    bool isvalid(TreeNode* root, long long minv, long long maxv){
        if(root == NULL)
            return true;
        if(root->val <= minv || root->val >= maxv)
            return false;
        return isvalid(root->left,minv,root->val) && isvalid(root->right,root->val,maxv);
    }
    bool isValidBST(TreeNode* root) {
        //inorder can be a solution but better is of range
        long long  minv=LLONG_MIN,maxv= LLONG_MAX;
        return isvalid(root,minv,maxv);
    }
};