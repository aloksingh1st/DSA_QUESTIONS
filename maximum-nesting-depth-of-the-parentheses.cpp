class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, current_depth = 0;

        for(auto ch : s){
            if(ch == '('){
                current_depth++;
            }
            else if(ch == ')'){
                current_depth--;
            }
            max_depth = max(current_depth, max_depth);
        }


        return max_depth;
    }
};