class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        int length = 1;
        unordered_set<char> charSet;
        int i = 0;
        charSet.insert(s[i]);

        for(int j = 1; j < s.size(); j++) {
            while(charSet.find(s[j]) != charSet.end()) {
                charSet.erase(s[i]);
                i++;
            }
            charSet.insert(s[j]);
            length = max(length, j - i + 1);
        }

        return length;

    }
};
