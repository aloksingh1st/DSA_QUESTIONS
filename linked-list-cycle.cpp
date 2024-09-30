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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;

        while(slow != NULL && fast != NULL &&  fast->next != NULL){

            if(cnt != 0 && slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }

        return false;

    }
};