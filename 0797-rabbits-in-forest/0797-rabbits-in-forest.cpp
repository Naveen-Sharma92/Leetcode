class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int>m;
       int ans=0;
       for(int i=0;i<answers.size();i++){
        m[answers[i]]++;
        if(answers[i]==0){
        }
       }
       for(auto it:m){
        if(it.first>it.second+1){
            ans+=((it.first)+1);
        }
        else{
            int k= ceil((it.second*1.0)/(it.first+1));
            ans+=(k*(it.first+1));

        }
       }
       return ans;
    }
};