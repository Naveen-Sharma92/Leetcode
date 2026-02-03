//wrong ans

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n=ratings.size();
//         int ans=n;
//         for(int i=0;i<n-1;i++){
//             if(ratings[i]!=ratings[i+1])
//                 ans++;
//         }
//         return ans;
//     }
// };

//we need to do double pass hint(chatgpt)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>v(n,1);
        int ans=0;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                v[i]=v[i-1]+1;
            }
        }
        for(int i=n-1;i>=1;i--){
            if(ratings[i-1]>ratings[i]){
                v[i-1]=max(v[i-1],v[i]+1);
            }
        }
        for(int i=0;i<n;i++)
            ans+=v[i];
        return ans;
    }
};