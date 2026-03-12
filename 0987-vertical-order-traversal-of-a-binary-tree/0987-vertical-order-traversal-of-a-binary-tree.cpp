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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            int r=it.second.first;
            int c=it.second.second;
            TreeNode* node=it.first ;
            q.pop();
            mpp[c][r].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{r+1,c-1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{r+1,c+1}});
            }
        }
        for(auto it:mpp){
            vector<int>v;
            for(auto it1: it.second){
                for(auto x : it1.second){
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};