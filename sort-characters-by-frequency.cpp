class Solution {
public:
    string frequencySort(string s) {
     unordered_map<char, int> freqMap;
    for (char c : s) {
        freqMap[c]++;
    }

    // Step 2: Sort the characters based on frequency
    // Create a vector of pairs (char, freq) for sorting
    vector<pair<int, char>> freqVec;
    for (auto& entry : freqMap) {
        freqVec.push_back({entry.second, entry.first});
    }

    // Sort the vector by frequency in decreasing order
    sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

    // Step 3: Build the result string
    string result = "";
    for (auto& entry : freqVec) {
        result += string(entry.first, entry.second);
    }

    return result;
    }
};