// Two pointer soln
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) {
            return 0;
        }

        int l = 0, r = n - 1;
        int leftMax = height[0], rightMax = height[n - 1];
        int area = 0;

        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                area += leftMax - height[l];
            }
            else {
                r--;
                rightMax = max(rightMax, height[r]);
                area += rightMax - height[r];
            }
        }

        return area;
    }
};