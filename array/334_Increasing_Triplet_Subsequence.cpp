#include <bits/stdc++.h>
using namespace std;


 bool increasingTriplet(vector<int>& nums) {
    vector<int>lis;
        for(int i : nums)
        {
            auto lb = lower_bound(lis.begin(),lis.end(),i);
            if(lb == lis.end())
            lis.push_back(i);
            else
            *lb = i;
        }
        return lis.size()>=3;
    }

int main(){
    vector<int> a = {20,100,10,12,5,13};
    bool ans = increasingTriplet(a);

    cout<<ans<<" "<<endl;
    return 0;
}