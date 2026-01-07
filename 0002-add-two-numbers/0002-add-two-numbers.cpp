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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1;
        ListNode *t2=l2;
        int x,y;
        if(t1){
            x=t1->val;
        }
        else{
            x=0;
        }
        if(t2){
            y=t2->val;
        }
        else{
            y=0;
        }

        ListNode *head=new ListNode((x+y)%10);
        ListNode *temp=head;
        int c=(x+y)/10;
        if (t1) 
            t1 = t1->next;
        if (t2) 
            t2 = t2->next;

        while(t1!=NULL || t2!=NULL){
            if(t1){
                x=t1->val;
            }
            else{
                x=0;
            }
            if(t2){
                y=t2->val;
            }
            else{
                y=0;
            }
             temp->next=new ListNode((x+y+c)%10);
             c=(x+y+c)/10;
             temp=temp->next;
            if (t1) 
                t1 = t1->next;
            if (t2) 
                t2 = t2->next;
        }
        if(c>0){
            temp->next=new ListNode(c);
        }
        return head;

    }
};