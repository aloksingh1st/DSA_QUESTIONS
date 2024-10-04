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

ListNode* mergeLL(ListNode* first, ListNode* second){
     ListNode* t1 = first, *t2 = second;
   ListNode* temp = new ListNode(-1);
   ListNode* head = temp;

   while(t1 != NULL && t2 != NULL){
       if(t1->val < t2->val){
           temp->next = t1;
           t1 = t1->next;
           temp = temp->next;
       }

       else{
           temp->next = t2;
           t2 = t2->next;
           temp = temp->next;
       }
   }

   if(t1 != NULL){
       temp->next = t1;
   }


   if(t2 != NULL){
       temp->next = t2;
   }


   return head->next;
}


   ListNode* findMiddle(ListNode* head){
     ListNode* slow = head;
     ListNode* fast = head->next;


     while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
     }

return slow;

   }

    ListNode* sortList(ListNode* head) {
        if( head == NULL || head->next == NULL){
            return head;
        }


        ListNode* middle = findMiddle(head);

        ListNode* lefthead = head;
        ListNode * righthead = middle->next;
        middle->next = NULL;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);


        return mergeLL(lefthead, righthead);

    }
};