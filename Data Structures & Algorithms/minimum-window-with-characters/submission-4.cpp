class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.length() == 0) {
            return "";
        }

        unordered_map<char, int> window, tCount;

        // build freq map for t string
        for (char ch : t) {
            tCount[ch]++;
        }

        int have = 0, required = tCount.size();
        int l = 0, r = 0;

        // To store the start of the current min window
        int minStartIndex = 0;
        int minWindowLength = INT_MAX;

        while (r < s.length()) {
            window[s[r]]++;

            if (tCount[s[r]] != 0 && window[s[r]] == tCount[s[r]]) {
                have++;
            }

            // shrink the window until - have != required
            while (have == required) {
                if (r - l + 1 < minWindowLength) {
                    minStartIndex = l;
                    minWindowLength = r - l + 1;
                }

                window[s[l]]--;
                if (tCount[s[l]] != 0 && window[s[l]] < tCount[s[l]]) {
                    have--;
                }
                l++;
            }
            r++;
        }

        if (minWindowLength == INT_MAX) {
            return "";
        }

        return s.substr(minStartIndex, minWindowLength);
    }
};
