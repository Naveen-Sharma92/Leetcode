class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>st;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                if(c!=0)
                    ans+='(';
                c++;
            }
            else if(s[i]==')'){
                st.pop();
                c--;
                if(c!=0)
                    ans+=')';
            }
        }
        return ans;
    }
};