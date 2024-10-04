/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
     ListNode* temp1 = head1;
     ListNode* temp2 = head2;

     while(temp1 != temp2){

        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1= head2;

        if(temp2 == NULL) temp2 = head1;
     }

     return temp1;
    }
};