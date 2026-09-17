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
    void rec(TreeNode *root,string &temp, vector<string>&ans){
        if(root==NULL)
            return;
        int n=temp.size();
        if(root->right==NULL && root->left==NULL){
            temp+=to_string(root->val);
            ans.push_back(temp);
            while(temp.size()>n)  //cannot do pop just 3 times because 123 is a single number but 3 characters
            temp.pop_back();
            return;
        }

        temp+=to_string(root->val);
        temp+="->";
        rec(root->left,temp,ans);
        rec(root->right,temp,ans);
        while(temp.size()>n)  //cannot do pop just 3 times because 123 is a single number but 3 characters
            temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        vector<string>ans;
        rec(root,temp,ans);
        return ans;
    }
};