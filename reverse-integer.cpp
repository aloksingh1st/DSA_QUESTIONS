class Solution {
public:
    int reverse(int x) {

        int n = x;
        int ans = 0;
        while(n != 0){

        int y = n % 10;
        ans = ans * 10 + y ;

        n = n / 10;

        }
        return ans;
    }
};