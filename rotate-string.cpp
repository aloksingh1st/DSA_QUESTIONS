class Solution {
public:


void rotateOne(string &s){
    if(s.empty()){
        return;
    }
    
    char lastChar = s.back();
    
    s.pop_back();
    s = lastChar + s;
}

    bool rotateString(string s, string goal) {
    int cnt = s.size();
    
    while(cnt){
        // ans++;
        rotateOne(s);
        if(s == goal){
            return true;
        }
        cnt--;
    }

    return false;
    }
};