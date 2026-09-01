/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,pair<int,ListNode*>>,vector<pair<int,pair<int,ListNode*>>>,greater<pair<int,pair<int,ListNode*>>>>pq;
        // value,LL index, vpointer to value in that LL
        int k = lists.size();
        vector<ListNode*> v=lists;
        for(int i=0;i<k;i++){
            ListNode *a=v[i];
            if(a!=NULL){
                pq.push({a->val,{i,v[i]}}); // only for 1t index of all
                v[i]= v[i]->next;
            }
        }
        ListNode* anshead= NULL;
        ListNode *curr=NULL;

        while(!pq.empty()){
            int v = pq.top().first;
            int j = pq.top().second.first;
            ListNode* c = pq.top().second.second;
            pq.pop();
            
            if(anshead == NULL) {
                anshead = new ListNode(v);
                curr = anshead;
            }
            else {
                curr->next = new ListNode(v);
                curr = curr->next;
            }

            if(c->next != NULL) {
                pq.push({c->next->val, {j, c->next}});
            }
        }

        return anshead;
    }
};