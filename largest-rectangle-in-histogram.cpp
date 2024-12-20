class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack to store indices of histogram bars
        vector<int> stack;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use a sentinel (0 height) at the end
            int current_height = (i == n) ? 0 : heights[i];

            // Maintain the stack such that heights are in increasing order
            while (!stack.empty() && current_height < heights[stack.back()]) {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = stack.empty() ? i : i - stack.back() - 1; // Calculate width
                max_area = std::max(max_area, height * width);
            }

            stack.push_back(i);
        }

        return max_area;
    }
};
