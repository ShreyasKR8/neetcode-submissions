
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> freqArr; //<freq, element>
        vector<int> result;

        for(int ele : nums) {
            freqMap[ele]++;
        }

        for(auto itr : freqMap) {
            freqArr.push_back({itr.second, itr.first});
        }

        std::sort(freqArr.rbegin(), freqArr.rend());

        for(int i = 0; i < k; i++) {
            result.push_back(freqArr[i].second);
        }

        return result;


    }
};
