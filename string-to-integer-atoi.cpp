class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1; // To track if the number is positive or negative
        int i = 0;
        int n = s.size();
        
        // Skip leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }
        
        // Check for sign
        if(i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Process digits and construct the number
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow/underflow
            if(ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        
        // Apply the sign
        return ans * sign;
    }
};
