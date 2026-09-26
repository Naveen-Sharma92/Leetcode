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
    TreeNode* makeBT(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &mpp){
        if(postStart>postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot=mpp[root->val];
        int numRight=inEnd-inRoot;

        root->right=makeBT(postorder,postEnd-numRight,postEnd-1,inorder,inRoot+1,inEnd,mpp);
        root->left=makeBT(postorder,postStart,postEnd-numRight-1,inorder,inStart,inRoot-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp; // value->inorder index
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root= makeBT(postorder,0,n-1,inorder,0,n-1,mpp);
        return root;
        
    }
};