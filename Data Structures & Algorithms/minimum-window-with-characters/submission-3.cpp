class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {
            return "";
        }

        int tLength = t.length();

        vector<int>sCount(128, 0);
        vector<int>tCount(128, 0);
        int minWindowSize = INT_MAX;
        int minStartIndex = 0;
        int formed = 0;
        int required = 0;

        for(int i = 0; i < tLength; i++) {
            if(tCount[t[i]] == 0){
                required++;
            }
            tCount[t[i]]++;
        }
        
        for(int i = 0; i < tLength; i++) {
            sCount[s[i]]++;
            if(tCount[s[i]] != 0 && sCount[s[i]] == tCount[s[i]]) {
                formed++;
            }
        }

        cout<<formed<<" "<<required;

        if(formed == required) {
            minWindowSize = min(minWindowSize, tLength);
        }

        int l = 0, r = tLength;
        while(r < s.size()) {
            sCount[s[r]]++;
            if(tCount[s[r]] != 0 && sCount[s[r]] == tCount[s[r]]) {
                formed++;
            }

            while(formed == required) {
                if(r - l + 1 < minWindowSize) {
                    minWindowSize = r - l + 1;
                    minStartIndex = l;
                }
                
                sCount[s[l]]--;
                if(tCount[s[l]] != 0 && sCount[s[l]] < tCount[s[l]]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        if(minWindowSize == INT_MAX) {
            return "";
        }

        return s.substr(minStartIndex, minWindowSize);
    }
};
