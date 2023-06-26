#include <bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n==0 or n==1){return n;}
       return  fibo(n-2)+fibo(n-1);
}

int main(){

    int n = 3;

    cout<< fibo(n)<<endl;
    return 0;
}