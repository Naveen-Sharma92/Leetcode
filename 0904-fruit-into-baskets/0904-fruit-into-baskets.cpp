class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int prev=fruits[0],current=fruits[0],pf=0,cf=0,ans=0,previ=0;
       for(int i=0;i<fruits.size();i++){
        if(fruits[i]==current){
            cf++;
        }
        else if(fruits[i]== prev){
            pf++;
        }
        else{
            
            if(fruits[i-1]== current){
                prev = fruits[i];
                pf=1;
            }
            else{
                current = fruits[i];
                cf=1;
            }
            if(fruits[previ]== current)
                previ++;
        }
        ans = max(ans,cf+pf);
       }
       return ans;
    }
};