class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
    int bannedCount = 0;

    // Iterate through the message array
    for (const string& word : message) {
        if (bannedSet.find(word) != bannedSet.end()) {
            bannedCount++;
            if (bannedCount >= 2) {
                return true; // If at least two banned words are found, return true
            }
        }
    }
    return false; // Otherwise return false
    }
};