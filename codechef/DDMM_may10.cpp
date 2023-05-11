#include <bits/stdc++.h>
using namespace std;
void check(string s){
      int num1 = stoi(s.substr(0, 2));
      int num2 = stoi(s.substr(3, 5));
      if(num1>12 && num2<=12) cout<<"DD/MM/YYYY"<<endl;
      if(num1<=12 && num2>12) cout<<"MM/DD/YYYY"<<endl;
      else if(num1<=12 && num2<=12) cout<<"Both"<<endl;
      }
int main() {
  int t;
  cin>>t;
  while(t--){
      string s;
      cin>>s;
      check(s);
       }
  return 0;