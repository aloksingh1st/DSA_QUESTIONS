class Solution {
public:

string removeExtraSpaces(const string &str) {
   stringstream ss(str);
   string word, result;

    while (ss >> word) {
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }

    return result;
}

    string reverseWords(string str) {
   string s = removeExtraSpaces(str);
        string temp = "", ans = "";
        int n = s.size();

        // Step 2: Traverse the string from the end
        for (int i = n - 1; i >= 0; i--) {
            // Build each word in reverse
            if (s[i] != ' ') {
                temp = s[i] + temp;
            }

            // If a space or start of the string is found, append the word
            if (s[i] == ' ' || i == 0) {
                if (!temp.empty()) {
                    if (!ans.empty()) {
                        ans += ' ';
                    }
                    ans += temp;
                    temp = "";
                }
            }
        }

        return ans;
    }
};