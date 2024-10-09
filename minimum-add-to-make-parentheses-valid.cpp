class Solution {
public:
    int minAddToMakeValid(string s) {
         int balance = 0;
        int needed = 0;

        for (auto ch : s) {
            if (ch == '(') {
                balance++;
            } else if (ch == ')') {
                balance--;
            }

            // If balance is negative, we have an unmatched closing parenthesis
            if (balance < 0) {
                needed++; // We need one more '('
                balance = 0; // Reset balance since we accounted for the unmatched ')'
            }
        }

        // Add remaining unmatched opening parentheses
        return needed + balance;
    }
};