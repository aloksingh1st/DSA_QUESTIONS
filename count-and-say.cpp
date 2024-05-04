class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        if(n==1)
            return prev;
        for(int i=2;i<=n;i++)
        {
            string curr = "";
            for(int j=0;j<prev.length();j++)
            {
                int count = 1 ;
                int k=j;
                while(k+1<prev.length()&&prev[k]==prev[k+1])
                {
                    k++;
                    count++;
                }
                j=k;
                curr+=(to_string(count)+to_string(prev[j]-'0'));
            }
            prev = curr;
        }
        return prev;
    }
};