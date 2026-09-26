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
    TreeNode* makeBT(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder, int inStart,int inEnd,unordered_map<int,int> &mpp){
        if(preStart>preEnd || inStart > inEnd)
            return NULL;
        TreeNode *root= new TreeNode(preorder[preStart]); // as start of preorder is root;
        int inRoot= mpp[root->val]; // to get the index of root in inorder
        int numLeft=inRoot-inStart;//to get how many are in  left side of the root
        root->left= makeBT(preorder,preStart+1,preStart+numLeft,inorder,inStart,inRoot-1,mpp);
        root->right= makeBT(preorder,preStart+numLeft+1,preEnd,inorder,inRoot+1,inEnd,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp; // to save inorder index of all nodes value
        int n= inorder.size();
        for(int i=0;i<n;i++)
            mpp[inorder[i]]=i;
        TreeNode* root= makeBT(preorder,0,n-1,inorder,0,n-1,mpp);// see vid
        return root;
    }
};