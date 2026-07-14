class Solution {
public:
    void rec(int n,int counts,int counte,string &temp, vector<string> &ans){
        if(counts==n && counte ==n){
            ans.push_back(temp);
            return;
        }
        if(counts>n || counte >n)
            return;
        if(counts<n){
            temp.push_back('(');
            rec(n,counts+1,counte,temp,ans); // do not use counts++ because below counts > counte heppen cannot done by modified
            temp.pop_back();
        }  

        if(counts>counte){
            temp.push_back(')');
            rec(n,counts,counte+1,temp,ans); 
            temp.pop_back();  
        }
        return;   

    }
    vector<string> generateParenthesis(int n) {
        int counts=0,counte=0;
        vector<string>ans;
        string temp;
        rec(n,counts,counte,temp,ans);
        return ans;
    }
};