class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxF = 0;
        int maxLength = 0;
        unordered_map<char, int> freq;

        while(r < s.size()) {
            freq[s[r]]++;
            maxF = max(maxF, freq[s[r]]);
            while((r - l + 1) - maxF > k) {
                freq[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, (r - l + 1));
            r++;
        }

        return maxLength;
    }
};
