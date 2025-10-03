class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m,n;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            n[t[i]]++;
        }
        if(m==n)
            return true;
        return false;

    }
};