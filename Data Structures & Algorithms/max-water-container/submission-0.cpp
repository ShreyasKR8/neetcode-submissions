class Solution {
public:
    int maxArea(vector<int>& heights) {
        int resArea = 0;
        int i = 0;
        int j = heights.size() - 1;

        while(i < j) {
            int l = min(heights[i], heights[j]);
            int b = j - i;
            resArea = max(resArea, (l * b));
            if(heights[j] < heights[i]) {
                j--;
            }
            else{
                i++;
            }
        }

        return resArea;
    }
};
