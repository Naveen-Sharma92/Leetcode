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
    pair<int,int> maxDepth(TreeNode* root,int maxi) {
        if(root==NULL)
            return {0,0};
        auto it1=maxDepth(root->left,maxi);
        int maxi1= it1.second;
        auto it2=maxDepth(root->right,maxi);
        int maxi2= it2.second;
        maxi=max(maxi1,maxi2);
        int lh= it1.first;
        int rh= it2.first;
        maxi=max(maxi,lh+rh);
        return {1+max(lh,rh),maxi};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto it=maxDepth(root,0);
        return it.second;
    }
};