class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_map<string, char> n;
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);      
        }

        if(pattern.size()!=words.size())
            return false;

        for(int i=0;i<pattern.size();i++){
            char c = pattern[i];
            string w = words[i];
            if(m[c]=="" && n[w]=='\0'){
                m[c]=w;
                n[w]=c;
            }
            else if((m[c]!="" &&n[w]=='\0') || (m[c]=="" &&n[w]!='\0'))
                return false;
            else{
                if(m[c]==w && n[w]==c)
                    continue;
                else
                    return false;
            }

        
        }
        return true;
    }
};