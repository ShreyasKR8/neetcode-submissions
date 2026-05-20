
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result;

        for(int ele : nums) {
            freqMap[ele]++;
        }

        for(auto itr : freqMap) {
            minHeap.push({itr.second, itr.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;


    }
};
