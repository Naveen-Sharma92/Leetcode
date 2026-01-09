/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode*temp1=headA,*temp2=headB;
//         int c1=0,c2=0;
//         while(temp1){
//             c1++;
//             temp1=temp1->next;
//         }
//         temp1=headA;
        
//         while(temp2){
//             c2++;
//             temp2=temp2->next;
//         }
//         temp2=headB;
//         int diff=abs(c1-c2);
//         if(c1>c2){
//             while(diff>0){
//                 diff--;
//                 temp1=temp1->next;
//             }
//         }
//         else{
//             while(diff>0){
//                 diff--;
//                 temp2=temp2->next;
//             }
//         }
//         while((temp1) && (temp2)){
//             if(temp1==temp2)
//                 return temp1;
//             temp1=temp1->next;
//             temp2=temp2->next;
//         }
//         return NULL;
//     }
// };
// second method head1 when become null start from headb simliliarly if headb become Null start from haedA if they meet 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;

        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            pA = (pA == NULL) ? headB : pA->next;
            pB = (pB == NULL) ? headA : pB->next;
        }

        // Either intersection node or NULL
        return pA;
    }
};
