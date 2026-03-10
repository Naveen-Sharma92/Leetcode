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
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxi=root->val;
        int a=maxDepth(root,maxi);
        return maxi;
    }
private:
    int maxDepth(TreeNode* root,int& maxi){
        if(root==NULL)
            return 0;
        int lh=max(0,maxDepth(root->left, maxi)); // i do the mistake of not ignoring -ve sum branch
        int lr=max(0,maxDepth(root->right,maxi)); // i ignore max function 
        maxi=max(maxi,lh+lr+root->val);

        //return lh+lr+root->val;   lh and lr will become wrong as they cover both side not max side
        return root->val +max(lh,lr);
    }
};