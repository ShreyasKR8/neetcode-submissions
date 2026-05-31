class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int count = 1;
        int currentCount = 1;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] - nums[i - 1] == 1) {
                currentCount++;
            } else {
                if (currentCount > count) {
                    count = currentCount;
                }
                currentCount = 0;
            }
        }

        //if 
        if (currentCount > count) {
            count = currentCount;
        }

        // cout<<count;
        return count;
    }
};
