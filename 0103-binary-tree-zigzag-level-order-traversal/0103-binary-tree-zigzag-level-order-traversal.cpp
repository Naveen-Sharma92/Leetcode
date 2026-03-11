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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        stack<TreeNode*>s;
        if(root==NULL)
            return ans;
        bool y=true;
        s.push(root);
        while(!s.empty()){
            vector<int>v;
            queue<TreeNode*>q;
            while(!s.empty()){
                TreeNode* node =s.top();
                s.pop();
                q.push(node);
            }
            while(!q.empty()){
                TreeNode* node =q.front();
                v.push_back(node->val);
                q.pop();
                if(y){
                    if(node->left!=NULL){
                        s.push(node->left);
                    }
                    if(node->right!=NULL){
                        s.push(node->right);
                    }
                }
                else{
                    if(node->right!=NULL){
                        s.push(node->right);
                    }
                    if(node->left!=NULL){
                        s.push(node->left);
                    }
                    
                }
            }
            ans.push_back(v);
            y=!y;

        }
        return ans;
        
    }
};