#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string a, string b){
    string ans = "";
    int i = 0, n = b.length();
    bool complete = false;

    for(auto c: a){
        ans += c;
        if(!complete){
        ans+= b[i++];
        if(i==n) complete = true;
        }
    }
    while(!complete){
    ans +=b[i++];
    if(i==n) complete = true;

    } 

    return ans;

}
int main(){
    string word1 = "abc", word2="pqrs";
    string w = mergeAlternately(word1, word2);
    cout<<w<<endl;
    return 0;
}
