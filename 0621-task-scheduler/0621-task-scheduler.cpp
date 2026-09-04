class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int c=1;
        int s= tasks.size();
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,char>>pq; //max heap of freq,char 1st queue
        for(int i=1;i<s;i++){
            if(tasks[i-1]!=tasks[i]){
                pq.push({c,tasks[i-1]});
                c=1;
                continue;
            }
            c++;
        }
        pq.push({c,tasks[s-1]});

        queue<pair<pair<int,char>,int>>q; // cooldown 2nd q where we store freq,task,time it will be available;
        int anstime=0;
        while((!pq.empty()) || (!q.empty())){
            anstime++;
            // below is right and pass but a bug as i need to add all that is available to pq otherswise the most frequent one does not add to pq
            // if(!q.empty()){
            //     int f=q.front().first.first;
            //     char ch=q.front().first.second;
            //     int t=q.front().second;
            //     if(t<=anstime){ // check cooldown is over <= not == as at same time more can be cooldown but can call one only
            //         pq.push({f,ch});
            //         q.pop();
            //     }
            // }
            while(!q.empty() && q.front().second <= anstime){// check cooldown is over <= not == as at same time more can be cooldown but can call one only
                pq.push(q.front().first);
                    q.pop();
            }

            if(!pq.empty()){
                int f= pq.top().first;
                int ch=pq.top().second;
                pq.pop();
                f--;
                if(f>0){
                    q.push({{f,ch},anstime+n+1});
                }
            }

        }
        return anstime;
        
    }
};