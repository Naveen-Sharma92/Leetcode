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
    void makemap(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mpp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->right !=NULL){
                q.push(node->right);
                mpp[node->right]=node;
            }
            
            if(node->left !=NULL){
                q.push(node->left);
                mpp[node->left]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // making a map with all the child as key and parent as value;
        vector<int>ans;
        if(root==NULL)
            return ans;
        unordered_map<TreeNode*,TreeNode*>mpp;
        unordered_map<TreeNode*,bool>vis;
        makemap(root,mpp);
        queue<pair<TreeNode*,int>>q; //TreeNode,dis
        vis[target]=true;
        q.push({target,0});
        while(!q.empty()){
            TreeNode* node= q.front().first;
            int dis=q.front().second;
            q.pop();
            if(dis==k)
                ans.push_back(node->val);
            else{
                if(node->left!=NULL && vis.find(node->left)==vis.end()){ //left
                    vis[node->left]=true;
                    q.push({node->left,dis+1});
                }
                if(node->right!=NULL && vis.find(node->right)==vis.end()){//right
                    vis[node->right]=true;
                    q.push({node->right,dis+1});
                }
                if(mpp.find(node)!=mpp.end() && vis.find(mpp[node])==vis.end()){//parent
                    vis[mpp[node]]=true;
                    q.push({mpp[node],dis+1});
                }
            }
        }
        return ans;

        
    }
};