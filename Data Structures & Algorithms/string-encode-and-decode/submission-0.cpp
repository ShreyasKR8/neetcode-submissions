/*-----------------Length prefixing------------ */
#include<string>
class Solution {
public:
    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string encodedStr = "";
        for(int i = 0; i < strs.size(); i++) {
            encodedStr += to_string(strs[i].size());
            if(i == strs.size() - 1) {
                encodedStr += "#";
            }
            else{
                encodedStr += ",";
            }
        }

        for(string str : strs) {
            encodedStr += str;
        }
        
        cout<<encodedStr;
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<int>lengths;
        vector<string> decodedStrs;

        if(s.empty()) {
            return {};
        }

        int i = 0;

        // storing the lengths of each string
        while(s[i] != '#') {
            string numStr = "";
            while(s[i] != ',' && s[i] != '#') {
                numStr += s[i];
                i++;
            }
            // cout<<numStr;
            int num = stoi(numStr);
            lengths.push_back(num);
            if(s[i] == ',')
            {
                i++;
            }
        }

        // Inc the index to the char after #.
        i++;

        //extract each string based on lengths.
        for(int j = 0; j < lengths.size(); j++) {
            int length = lengths[j];
            string str = s.substr(i, length);
            decodedStrs.push_back(str);
            i += length;
        }

        return decodedStrs;
    }
};
