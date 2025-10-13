class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>s;
        int c=1;
        for(int i=1;i<words.size();i++){
            string a= words[i-1];
            sort(a.begin(),a.end());
            string b=words[i];
            sort(b.begin(),b.end());
            if(a==b){
                c++;
            }
            else{
                s.push_back(words[i-c]);
                c=1;
            }
        }
        s.push_back(words[words.size()-c]);
        return s;
        
    }
};