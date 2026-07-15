//practice with set - One of those days ¯\_(ツ)_/¯
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        set<int> numSet;
        int longest = 1;

        for(int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }

        for(int ele : numSet) {
            if(!numSet.contains(ele - 1)) { //indicates potential starting number of a consec seq
                int count = 1;
                while(numSet.contains(ele + count)) {
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};
