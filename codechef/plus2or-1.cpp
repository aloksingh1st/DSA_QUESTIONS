#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	
	cin >>t;
	
	while(t--){
	    int n;
	    cin >>n;
	    if(n!= 0){
	        cout<<2*n+n<<endl;
	    }
	    else{
	        cout<<1<<endl;
	    }
	}
	return 0;
}
