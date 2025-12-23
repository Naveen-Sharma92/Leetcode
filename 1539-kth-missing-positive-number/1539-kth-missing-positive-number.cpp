// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int c=0,j=1;
//         bool l=true;
//         while(1){
//             for(int i=0;i<arr.size();i++){
//                 if(arr[i]==j){
//                     l=false;
//                     break;
//                 }
//             }
//             if(l){
//                 c++;
//             }
//             if(c==k){
//                 return j;
//             }
//             j++;
//             l=true;
//         }
//         return j;
//     }
// };


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int n=arr.size();
       int low=0,high=n-1;
       while(high>=low){
        int mid=low+(high-low)/2,mis=arr[mid] - (mid + 1);
        if(mis>=k)
            high=mid-1;
        else
            low=mid+1;
       }
       return low+k;
    }
};