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
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head,*slow=head;
        if(head==NULL || head->next==NULL)
            return true;
        if(head->next->next==NULL)
            return head->next->val == head->val;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*temp=slow->next,*prev=NULL;
        // now we reverse the half
        while(temp){
            ListNode* fut=temp->next;
            temp->next=prev;
            prev=temp;
            temp=fut;
        }
        slow->next=prev;
        fast=head;
        temp=prev;
        while(prev!=NULL){
            if(prev->val==fast->val){
                prev=prev->next;
                fast=fast->next;
                continue;
            }
            return false;
        }
        return true;

        
    }
};