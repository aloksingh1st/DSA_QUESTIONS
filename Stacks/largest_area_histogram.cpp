#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // For max function

using namespace std;

class Solution
{
public:
    // Modified checkMaxArea to correctly calculate areas considering index
    int checkMaxArea(list<int> st, int max_area, int current_index)
    {
        int index = 0; // Initialize index counter

        for (auto it = st.begin(); it != st.end(); ++it, ++index)
        {
            int height = *it;
            int width = (current_index - index); // Width depends on current index
            int area = width * height;          // Calculate area
            max_area = max(area, max_area);     // Update max_area
        }

        return max_area; // Return the maximum area
    }

    int largestRectangleArea(vector<int> &heights)
    {
        list<int> st;
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < st.back())
            {
                max_area = checkMaxArea(st, max_area, i);
                st.pop_back();
            }

            st.push_back(heights[i]);
        }

        // Handle the remaining elements in the stack
        max_area = checkMaxArea(st, max_area, heights.size());

        return max_area;
    }
};

int main()
{
    // Example test case
    vector<int> heights = {2, 1, 2};

    Solution solution;
    int max_area = solution.largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << max_area << endl;

    return 0;
}

