class Solution {
public:
    bool checkRecord(string s) {
        int c=0;
        int maxi= 0;
       map<char,int>m;
       int n= s.size();
       for(int i=0;i<n;i++){
        m[s[i]]++;
        if(s[i]== 'L')
            c++;
        else
            c=0;
        maxi = max(c,maxi);
       } 
       if(m['A'] >=2)
            return false;

        if(maxi >= 3)
            return false;
        return true;
    }
};