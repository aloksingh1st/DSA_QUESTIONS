class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapstr[256] = {0};
        int ischarMap[256] = {0};


        for(int i=0;i<s.size(); i++){
            if(mapstr[s[i]] == 0 && ischarMap[t[i]] == 0){
                mapstr[s[i]] = t[i];
                ischarMap[t[i]] = 1;
            }
        }

        for(int i=0; i<s.size(); i++){
            if(char(mapstr[s[i]]) != t[i]){
                return false;
            }
        }

        return true;
    }
};