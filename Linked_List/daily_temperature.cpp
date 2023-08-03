class Solution {
public:
   vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<deque<int>>v(101);
        for(int i=0;i<temperatures.size();i++)
        {
            v[temperatures[i]].push_back(i+1);
        }
        vector<int>ans;
        for(int i=0;i<temperatures.size();i++)
        {
            int res=0;
            for(int j=temperatures[i]+1;j<101;j++)
            {
                if(!v[j].empty())
                {
                    if(v[j].front()>i+1)
                     {if(res)res=min(res,v[j].front()-i-1);
                    else res=v[j].front()-i-1;}
                }
                if(res==1)break;
            }
            ans.push_back(res);
            v[temperatures[i]].pop_front();
        }
        return ans;
   }
};
