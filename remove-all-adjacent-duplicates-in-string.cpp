class Solution {
public:
    string removeDuplicates(string s) {
        list<char> st;

        for(auto ch : s){
            if(!st.empty() && st.back() == ch){
                st.pop_back();
            }
            else{
                st.push_back(ch);
            }
        }


string ans ="";

         for (char value : st) {
        ans += value;
    }

    return ans;
    }
};