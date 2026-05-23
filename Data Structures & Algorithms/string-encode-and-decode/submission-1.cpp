class Solution {
public:
    // length#string
    string encode(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        string encodedStr = "";
        for(string str : strs) {
            encodedStr += to_string(str.size()) + "#" + str;
        }

        cout<<encodedStr;
        return encodedStr;
    }

    vector<string> decode(string s) {
        if(s.empty()) {
            return {};
        }

        vector<string> decodedStr;
        int i = 0;

        while(i < s.size()) {
            string lengthStr = "";
            while(s[i] != '#') {
                lengthStr += s[i];
                i++;
            }
            i++; //skip '#'
            int length = stoi(lengthStr);
            decodedStr.push_back(s.substr(i, length));
            i += length;
        }

        return decodedStr;
    }
};
