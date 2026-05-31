class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        int count = 1;
        int currentCount = 1;

        sort(nums.begin(), nums.end());
        // for(int num : nums) {
        //     cout<<num;
        // }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] - nums[i - 1] == 1) {
                currentCount++;
                // cout<<currentCount;
            } else {
                if (currentCount > count) {
                    count = currentCount;
                }
                currentCount = 1;
                // cout<<i;
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
