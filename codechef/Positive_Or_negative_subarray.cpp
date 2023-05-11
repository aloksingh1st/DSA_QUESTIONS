#include <iostream>
using namespace std;
//The code start from here
int main() {  
      int t;
       cin>>t;
        while(t--)
        {
            int n;
             cin>>n;
             int ar[n];
             for(int i=0;i<n;i++)
             {
             cin>>ar[i];
             }
             long p=0,q=0;
             for(int i=n-1;i>=0;i--)
             {
                 if(ar[i]==1)
                 {
                     p+=i+1;
                 }
                 else
                 {
                     q+=i+1;
                 }
             }
             if(p>q)
             cout<<p-q<<endl;
             else
             cout<<q-p<<endl;
             
             
        }
  // your code goes here
  return 0;
}