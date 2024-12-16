#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
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

int main()
{
    vector<int> nums = {1, 2, 1};
    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);

    // Output the result
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
