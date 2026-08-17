class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int a =-1;
        string ans;
        for(int i=n-1;i>=0;i--){
            if((int)num[i]%2!=0){
                a=i;
                break;
            }
        }
        if(a==-1)
            return "";
        else{
            for(int i=0;i<=a;i++)
                ans+=num[i];
        }
        return ans;
        
    }
};