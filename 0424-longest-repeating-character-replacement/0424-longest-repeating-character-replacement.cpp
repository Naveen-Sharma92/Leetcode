//wrong answer
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int count=0;
//         int ans =0;
//         int nk=k;
//         for(int r=0,l=0;l<s.size();l++){
//             if(s[l] == s[r]){
//                 l++;
//                 count++;
//             }
//             else{
//                 if(nk>0){
//                     nk--;
//                     l++;
//                 }
//                 else{
//                     count = k;
//                     while(s[l] != s[r]){
//                         r++;
//                     }
//                 }
                
//             }
//             ans = max(ans,r-l+1);

//         }
//         return ans+1;
//     }
// };

int max_freq(unordered_map<char,int>mpp){
    int maxFreq = 0;
    int maxKey = -1;
    
    for (const auto& pair : mpp) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            maxKey = pair.first;
        }
    }
    return maxFreq;
}
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0,max_len=0;
        unordered_map<char,int>mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            if((r-l+1)-max_freq(mpp) > k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                    mpp.erase(s[l]);
                l++;
            }
            if((r-l+1)-max_freq(mpp) <= k){
                max_len=max(max_len,r-l+1);
            }
            r++;

        }
        return max_len;
        
    }
};