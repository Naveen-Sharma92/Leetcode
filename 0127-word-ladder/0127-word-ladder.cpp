// class Solution {
// public:
//     int similar(string Word1, string Word2){
//         int k=0;
//         for(int i=0;i<Word1.size();i++){
//             if(Word1[i]!=Word2[i])
//                 k++;
//         }
//         return k;
//     }
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         wordList.push_back(beginWord);
//         int n=wordList.size();
//         vector<vector<int>>adj(n);
        
//         bool found = false;

//         for(auto &word : wordList){
//             if(word == endWord){
//             found = true;
//             break;
//             }
//         }

//         if(!found)
//             return 0;



//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(similar(wordList[i],wordList[j])==1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//     vector<int>dis(n,INT_MAX);
//     dis[n-1]=1;
//     queue<pair<int,int>>q;
//     q.push({n-1,1});

//     while(!q.empty()){
//         int a=q.front().first;
//         int d=q.front().second;
//         q.pop();

//         for(auto it:adj[a]){
//             if(wordList[it]==endWord)
//                 return dis[a]+1;
//             if(dis[it]>dis[a]+1){
//                 dis[it]=dis[a]+1;
//                 q.push({it,dis[a]+1});
//             }
//         }
//     }
//     return 0;
//     }
// };

// this above is my code
// below is striver optimised code

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>se(wordList.begin(),wordList.end());
        int n= beginWord.size();

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        se.erase(beginWord);
        while(!q.empty()){
            string a=q.front().first;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<n;i++){
                for(char w='a';w<='z';w++){
                    string s=a;
                    s[i]=w;
                    if(s==endWord && se.find(s) != se.end())   // EVEN IF S IS NOT IN SE WE DO IT SO FIRST NEED TO CHECK WHETHER S IS IN DICTIONARY OR NOT
                        return d+1;
                    else if(se.find(s) != se.end()){
                        q.push({s,d+1});
                        se.erase(s);
                    }
                }
            }
        }
    return 0;


    }
};