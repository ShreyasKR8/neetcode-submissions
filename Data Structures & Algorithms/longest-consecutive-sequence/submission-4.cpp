//practice with sorting - One of those days ¯\_(ツ)_/¯
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        int longest = 1, curr = 1;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                continue; //skip duplicates
            }
            else if(nums[i - 1] + 1 == nums[i]){
                curr++;
            }
            else {
                longest = max(curr, longest);
                curr = 1;
            }
        }

        longest = max(longest, curr);

        return longest;
    }
};
