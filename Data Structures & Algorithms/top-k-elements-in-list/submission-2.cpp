
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<vector<int>> freqBucket(nums.size() + 1); // + 1 to make the index 'nums.size()' valid
        vector<int> result;

        for(int ele : nums) {
            freqMap[ele]++;
        }

        for(auto itr : freqMap) {
            freqBucket[itr.second].push_back(itr.first);
        }

        for(int i = freqBucket.size() - 1; i > 0; i--) {
            for(int ele : freqBucket[i]) {
                result.push_back(ele);
                if(result.size() == k) {
                    return result;
                }
            }
        }

        return result;


    }
};
