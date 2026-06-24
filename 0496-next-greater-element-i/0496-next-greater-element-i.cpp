class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        
        int n= nums2.size();
        int m= nums1.size();
        vector<int>nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <=nums2[i])
                st.pop();
            if(st.empty())
                nge[i]=-1;
            else
                nge[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            int ind=find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            ans[i] = nge[ind];
        }
        return ans;
    }
};