class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0 ; i<9 ; i++){
            unordered_set <char> a;
            for(int j =0 ; j<9 ; j++){
                char c = board[i][j];
                if(c=='.') continue;
                if(a.find(c)==a.end()) a.insert(c);
                else return false;
            }
        }

        for(int i=0 ; i<9 ; i++){
            unordered_set <char> a;
            for(int j =0 ; j<9 ; j++){
                char c = board[j][i];
                if(c=='.') continue;
                if(a.find(c)==a.end()) a.insert(c);
                else return false;
            }
        }

        for(int i =0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                unordered_set <char> a;
                for(int k =0; k<3 ; k++){
                    for(int l=0;l<3 ; l++){
                        char c = board[k+3*i][l+3*j];
                        if(c=='.') continue;
                        if(a.find(c)==a.end()) a.insert(c);
                        else return false;
                    }
                }
            }
        }

        
        return true;
    }
};