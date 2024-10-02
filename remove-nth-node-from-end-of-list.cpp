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
    int countLLL(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            temp= temp->next;
            cnt++;
        }

        return cnt;
    }

     ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;

        int countLL = countLLL(head);  // Get the total count of nodes
        int fromFrontPosition = countLL - n;  // The position of the node to remove from the front

        // Edge case: if the node to be removed is the head (when n is equal to the list length)
        if (fromFrontPosition == 0) {
            ListNode* toremove = head;
            head = head->next;  // Update head to the next node
            delete toremove;    // Free the memory of the old head
            return head;        // Return the new head
        }

        ListNode* temp = head;
        int cnt = 1;

        // Traverse the list until you reach the node before the one to remove
        while (temp != NULL && cnt != fromFrontPosition) {
            temp = temp->next;
            cnt++;
        }

        // Now temp is pointing to the node before the one to be deleted
        if (temp != NULL && temp->next != NULL) {
            ListNode* toremove = temp->next;
            temp->next = temp->next->next;  // Skip the node to be deleted
            delete toremove;  // Free the memory of the node
        }

        return head;
    }
};