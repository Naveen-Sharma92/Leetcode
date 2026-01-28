// brute force tle
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int start_index=-1;
//         int min_length=INT_MAX;
//         int n=t.size(),m=s.size();
//         for(int i=0;i<m;i++){
//             vector<int> v(256, 0);
//             int cnt=0;
//             for(int j=0;j<n;j++)
//                 v[t[j]]++;
//             for(int j=i;j<m;j++){
//                 if(v[s[j]]>0)
//                     cnt++;
//                 v[s[j]]--;
//                 if(cnt==n){
//                     if(min_length>j-i+1){
//                         start_index=i;
//                         min_length=j-i+1;
//                     }
//                      break;
//                 }
//             }
//         }
//         if (start_index == -1)
//           return "";
//         return s.substr(start_index,min_length);
//     }
// };

class Solution {
public:
    string minWindow(string s, string t) {
       int l=0,r=0,n=t.size(),m=s.size(),min_length=INT_MAX,start_index=-1,cnt=0;;
       vector<int> v(256, 0);
       for(int j=0;j<n;j++)
             v[t[j]]++;
       while(r<m){
        if(v[s[r]]>0)
            cnt++;
        v[s[r]]--;
        while(cnt==n){
            if(min_length>r-l+1){
                start_index=l;
                min_length=r-l+1;
            }
            v[s[l]]++;
            if(v[s[l]]>0)
                cnt--;
            l++;
        }
        r++;
       }
       if (start_index == -1)
        return "";
       return s.substr(start_index,min_length);
    }
};