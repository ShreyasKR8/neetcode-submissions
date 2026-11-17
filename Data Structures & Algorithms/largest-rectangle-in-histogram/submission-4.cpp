//Recall
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int>leftMost(n, -1);
        vector<int> rightMost(n, n);
        int maxArea = 0;

        //precompute leftMost smaller ele for every ith height and store its index
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) {
                leftMost[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        //precompute rightMost smaller ele for every ith height and store its index
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) {
                rightMost[i] = st.top();
            }

            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            leftMost[i] += 1; // -1 => 0
            rightMost[i] -= 1; // n => n - 1
            int width = rightMost[i] - leftMost[i] + 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};
