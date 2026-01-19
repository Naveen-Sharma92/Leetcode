// got tle in 46th case brute force
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int ans=0,n=s.size();
//         for(int i=0;i<n;i++){
//             unordered_map<char,int>mpp;
//             mpp[s[i]]++;
//             for(int j=i+1;j<n;j++){
//                 mpp[s[j]]++;
//                 if(mpp.size()==3)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };

// better approch but get tle at 53th case out of 54
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int ans=0,n=s.size();
//         for(int i=0;i<n;i++){
//             unordered_map<char,int>mpp;
//             mpp[s[i]]++;
//             for(int j=i+1;j<n;j++){
//                 mpp[s[j]]++;
//                 if(mpp.size()==3){
//                     ans+=(n-j);
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

//best
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,lastseen[]={-1,-1,-1};
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                ans+=(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
            }
        }
        return ans;
    }
};
