class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0;
        int maxFreq = 0; // Maximum frequency of any character in the current window
        int l = 0, r = 0;
        int n = s.size();
        vector<int> freq(26, 0); // Frequency array for characters A-Z

        while (r < n) {
            freq[s[r] - 'A']++; // Increment frequency of the current character
            maxFreq = max(maxFreq, freq[s[r] - 'A']); // Update maxFreq

            // Current window size
            int windowSize = r - l + 1;

            // If replacements needed exceed k, shrink the window
            if (windowSize - maxFreq > k) {
                freq[s[l] - 'A']--; // Decrease frequency of the character leaving the window
                l++;
            }

            // Update maxCount to track the longest valid window
            maxCount = max(maxCount, r - l + 1);

            r++; // Expand the window
        }

        return maxCount;
    }
};
