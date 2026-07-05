//Updated to use inclusive prefix/suffix maximum arrays, 
// removing the need for clamping and aligning with the standard O(n) solution.
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int>prefixMax (size, 0);
        vector<int>suffixMax (size, 0);
        vector<int> minArr (size, 0);
        int area = 0;

        //pre compute left max
        prefixMax[0] = 
        for(int i = 1; i < height.size(); i++) {
            prefixMax[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        // pre compute right max
        maxHeight = height[size - 1];
        for(int i = size - 2; i >= 0; i--) {
            suffixMax[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        //pre compute min array
        for(int i = 0; i < size; i++) {
            minArr[i] = min(prefixMax[i], suffixMax[i]);
        }

        for(int i = 0; i < size; i++) {
            int currArea = minArr[i] - height[i];
            if(currArea > 0) {
                area += currArea;
            }
        }
        
        return area;
    }
};