class Solution {
public:
    void rec(int index,int currentsum,vector<int>& candidates, int target,vector<vector<int>> & ans,vector<int> &temp){
        if(currentsum==target){
            ans.push_back(temp);
            return;
        }
        if(currentsum>target)
            return;
        if(index>=candidates.size())
            return;
    //pick
    temp.push_back(candidates[index]);
    rec(index,currentsum+candidates[index],candidates, target,ans,temp);
    temp.pop_back();
    //not pick
    rec(index+1,currentsum, candidates, target,ans,temp);
    return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        int currentsum=0;
        vector<vector<int>>ans;
        vector<int>temp;
        rec(index,currentsum, candidates, target,ans,temp);
        return ans;
    }
};