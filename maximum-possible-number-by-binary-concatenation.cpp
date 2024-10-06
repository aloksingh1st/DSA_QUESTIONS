class Solution {
public:

string toBinary(int num) {
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}
    int maxGoodNumber(vector<int>& nums) {
    vector<string> binaries;
    for (int num : nums) {
        binaries.push_back(toBinary(num));
    }

    int maxValue = 0;

    // Generate all possible permutations of binaries
    sort(binaries.begin(), binaries.end());
    do {
        // Concatenate the current permutation of binary strings
        string concatenated = binaries[0] + binaries[1] + binaries[2];
        // Convert the concatenated binary string to a decimal number
        int decimalValue = stoi(concatenated, nullptr, 2);
        // Update maxValue if a larger number is found
        maxValue = max(maxValue, decimalValue);
    } while (next_permutation(binaries.begin(), binaries.end()));

    return maxValue;

    }
};