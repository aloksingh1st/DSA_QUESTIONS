class Solution {
public:
    int smallestNumber(int n) {
         int x = 1; // Start with the smallest number with set bits
    while (x < n) {
        x = (x << 1) | 1; // Shift left and set the next bit
    }
    return x;
    }
};