class Solution {
public:
   vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> st;
        vector<int> result(nums.size(), -1);

        for (int i = nums.size() * 2 - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % nums.size()])
            {
                st.pop();
            }

            if (i <= nums.size() - 1)
            {

                if (!st.empty())
                {
                    result[i] = st.top();
                }
            }

            st.push(nums[i % nums.size()]);
        }

        return result;
    }
};