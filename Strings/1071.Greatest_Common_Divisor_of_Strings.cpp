#include <bits/stdc++.h>
using namespace std;

 string gcdOfStrings(string str1, string str2) {
          return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
        
    }

int main(){
    string a = "ABCABC", b = "ABC";
    string ans = gcdOfStrings(a, b);

    cout << ans << endl;
    return 0;
}