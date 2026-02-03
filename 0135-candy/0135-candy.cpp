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

// my approch better brute is in copy
//we need to do double pass hint(chatgpt)


// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n=ratings.size();
//         vector<int>v(n,1);
//         int ans=0;
//         for(int i=1;i<n;i++){
//             if(ratings[i]>ratings[i-1]){
//                 v[i]=v[i-1]+1;
//             }
//         }
//         for(int i=n-1;i>=1;i--){
//             if(ratings[i-1]>ratings[i]){
//                 v[i-1]=max(v[i-1],v[i]+1);
//             }
//         }
//         for(int i=0;i<n;i++)
//             ans+=v[i];
//         return ans;
//     }
// };


//best
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1,sum=1;  // sum=1 because we are starting from index 1 not 0
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum+=1;
                i++;
            }
            else{
                int peak=1;
                while(i<n && ratings[i]>ratings[i-1]){
                    peak+=1;
                    sum+=peak;
                    i++;
                }
                int down=1;
                while(i<n && ratings[i]<ratings[i-1]){
                    sum+=down;
                    down+=1;
                    i++;
                }
                if(down-peak>0)
                    sum+=(down-peak);
            }
        }
        return sum;
    }
};

