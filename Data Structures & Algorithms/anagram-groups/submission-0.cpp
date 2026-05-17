class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
                unordered_map<string, vector<string>> aMap;
        vector<vector<string>> result;

        for(int i = 0; i < strs.size(); i++) {
            vector<int> freqArr(26, 0);
            string str = strs[i];

            for(char c : str) {
                freqArr[c - 'a']++;
            }
            string freqKey = "";
            for(int j = 0; j < freqArr.size(); j++) {
                freqKey += to_string(freqArr[j]) + "#";
            }

            aMap[freqKey].push_back(str);
        }

        for(auto itr : aMap) {
            result.push_back(itr.second);
        }

        return result;
    }
};
