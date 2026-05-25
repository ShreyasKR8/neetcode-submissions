class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>indexMap;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            // can also use count()
            if(indexMap.count(diff) && indexMap[diff] != i) {
                return{i, indexMap[diff]};
            }
        }
        return {};
    }
};
