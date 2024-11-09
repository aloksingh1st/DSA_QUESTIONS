class Solution {
public:
    int productOfDigits(int n) {
        int p = 1;
        while (n != 0) {
            p *= n % 10;
            n = n / 10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            int product = productOfDigits(n);
            if(product%t == 0) return n;

            n++;
        }
    }
};