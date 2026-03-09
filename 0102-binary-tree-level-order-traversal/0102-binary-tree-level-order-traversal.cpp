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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int j=q.size();
            vector<int>v;
            for(int i=0;i<j;i++){

                v.push_back(q.front()->val);
                if(q.front()->left!= NULL)
                    q.push(q.front()->left);
                if(q.front()->right!= NULL)
                    q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(v);
        }
        return ans;

    }
};