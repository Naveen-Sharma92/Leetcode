class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int l=0,r=n-1,ans=0;
        while(l<r){
            ans=max(ans,((r-l)*(max(height[r],height[l])-abs(height[r]-height[l]))));
            if(height[l]>=height[r])
                r--;
            else
                l++;
        }
        return ans;
        
    }
};