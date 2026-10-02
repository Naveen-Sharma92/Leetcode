/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                ans+="#,";
            }
            else{
                ans+=to_string(curr->val);
                ans+=',';
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n= data.size();
        if(n==0)
            return NULL;
        stringstream s(data);
        string str;// to get the current valur of a node one by one cannot do direct as 1 and 11 both can be value
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            

            
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));