// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
   
//         int max_count = 0;
//         for(int i=0;i<s.length();i++){
//             bool c =false;
//             int count =1;
//             for(int j = i+1;j<s.length();j++){
//                 for(int k=i;k<j;k++){
//                     if(s[j] == s[k])
//                         c = true;
//                 }
//                 if(c)
//                     break;
//                 count++;
//             }
//             if(max_count<count)
//                 max_count = count;
//         }
//         return max_count;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_count=0;
        int l=0,r=0;
        vector<int> m(256, -1); // works as a hasp map
        int n=s.size();
        while(r<n){
            if(m[s[r]]>=l){
                l=m[s[r]]+1;
            }
            m[s[r]]=r;
            max_count=max(max_count,r-l+1);
            r++;
        }
       
        return max_count;
    }
};