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
    // Rename reverse to reverseList to match the expected function signature
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    // Function to check if a linked list is palindrome
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Use two pointers to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* reversed = reverseList(slow);

        // Compare the two halves
        ListNode* current = head;
        while (reversed != nullptr) {
            if (current->val != reversed->val) {
                return false;
            }
            current = current->next;
            reversed = reversed->next;
        }

        return true;
    }
};
