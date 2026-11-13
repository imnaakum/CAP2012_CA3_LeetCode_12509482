// LeetCode 84 - Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        long long best = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentHeight) {
                int height = heights[st.top()];
                st.pop();

                int leftSmaller = st.empty() ? -1 : st.top();
                int width = i - leftSmaller - 1;
                best = max(best, 1LL * height * width);
            }

            if (i < n) st.push(i);
        }
        return static_cast<int>(best);
    }
};
