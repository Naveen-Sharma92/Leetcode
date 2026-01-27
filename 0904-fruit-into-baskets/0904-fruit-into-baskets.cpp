//chatgpt;
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         map<int,int >m;
//         int ans=0,map_size=0;
//         for(int i=0,j=0;j<fruits.size();j++){
//             m[fruits[j]]++;
//             if(m[fruits[j]] == 1){
//                 map_size++;
//             }
//             if(map_size >2){
//                 while(map_size>2){
//                     m[fruits[i]]--;
//                     if(m[fruits[i]] == 0)
//                         map_size--;
//                     i++;
//                 }
//             }
//             ans = max(ans,j-i+1);
//         }
//         return ans;
//     }
// };
 class Solution {
 public:
     int totalFruit(vector<int>& fruits) {
        int maxlen=0,r=0,l=0,n=fruits.size();
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                    mpp.erase(fruits[l]);
                l++;
            }
            else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
    };