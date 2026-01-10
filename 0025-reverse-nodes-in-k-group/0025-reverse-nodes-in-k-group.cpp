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
// ListNode* reverse(ListNode* first,ListNode*last){
//         ListNode* temp=first;
//         ListNode* prev=last->next;
//         ListNode* nextn=NULL;
//         while(temp!=last){
//             nextn=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=nextn;
//         }
//         if(temp==last){
//             nextn=NULL;
//             temp->next=prev;
//             prev=temp;
//             temp=nextn;
//         }
        
//         return prev;
// }
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode* temp=head,*first=head,*last=head,*prev=NULL;
//         int c=1;
//         while(first->next!=NULL){
//             while(c<=k)
//                 if(!last->next)
//                     last=last->next;
//                 else
//                     return head;
//             c=1;
//             ListNode* temp2=NULL;
//             temp2=reverse(first,last);
//             if(prev==NULL)
//                 head=temp2;
//             else
//                 prev->next=temp2;
//             prev=last;
//             last=last->next;
//             first=last;
//         }
//         return head;
        
//     }
// };

ListNode* reverse(ListNode* first,ListNode*last){
        ListNode* temp=first;
         ListNode* prev=last->next;
         ListNode* nextn=NULL;
         while(temp!=last){
            nextn=temp->next;
            temp->next=prev;
             prev=temp;
             temp=nextn;
         }
         if(temp==last){
             temp->next=prev;
             prev=temp;
             temp=NULL;
         }
        
        return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*first=head,*last=head,*prev=NULL;
        while(last){
            for(int i=1;i<k && last;i++){
                last=last->next;
            }
            if(!last)
                break;
            ListNode* temp2=reverse(first,last);
            if(prev==NULL){
                head=temp2;
                prev=first;
                first=first->next;
                last=first;
            }
            else{
                prev->next=temp2;
                prev=first;
                first=first->next;
                last=first;

            }

        }
        return head;
        
    }
};
