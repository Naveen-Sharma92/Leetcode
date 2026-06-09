class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // by using floyd algo

        vector<vector<int>>mat(n,vector<int>(n,1e8));
        int ansCity=0,cnt=n;
        for(auto it:edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]] = it[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)
                        mat[i][j]=0;
                    else
                        if(mat[i][k]!=1e8 && mat[k][j]!=1e8)
                            mat[i][j]= min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        for(int i=0;i<n;i++){  //city
        int c=0;
            for(int j=0;j<n;j++){
                if(i != j && mat[i][j] <=distanceThreshold){
                    c++;
                }
            }
            if(c<=cnt){
                cnt=c;
                ansCity=i;
            }
        }

        return ansCity;
    }
};