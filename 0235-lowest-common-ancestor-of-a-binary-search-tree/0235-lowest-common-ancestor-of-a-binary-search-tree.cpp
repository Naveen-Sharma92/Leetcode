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
        if(root ==NULL)
            return root;
        int cur=root->val;
        int pv =p->val;
        int qv =q->val;
        // if they exists at the same side of the node then go to that side otherwise retur the current node
        if(pv< cur && qv<cur)
            return lowestCommonAncestor(root->left,p,q);
        
        if(pv > cur && qv >cur)
            return lowestCommonAncestor(root->right,p,q);

        return root;
        
    }
};