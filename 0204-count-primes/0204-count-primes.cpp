class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool>v(n,true);
        if(n<=2)
            return 0;
        v[0]=false;
        v[1]=false;
        for(int i=2;i*i<n;i++){
            if(v[i])
                for(int j=i*i;j<n;j+=i)  // in this way we can stop duplicate checkings
                    v[j]=false;
        }
        for(int i=0;i<v.size();i++)
            cnt+=v[i];
        return cnt;
    }
};