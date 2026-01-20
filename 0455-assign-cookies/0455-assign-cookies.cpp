class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gr=0,sr=0,ans=0;
        while(gr<g.size() && sr<s.size()){
            if(g[gr]<=s[sr]){
                sr++;
                gr++;
                ans++;
            }
            else
                sr++;
        }
        return ans;
    }
};