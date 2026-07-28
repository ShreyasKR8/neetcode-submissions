// redo
class Solution {
public:

    string encode(vector<string>& strs) {
        vector<int> lengths;
        for(string str : strs) {
            lengths.push_back(str.length());
        }

        string res = "";

        for(int i = 0; i < lengths.size(); i++) {
            res += to_string(lengths[i]);
            if(i != lengths.size() - 1) {
                res += ",";
            }
        }

        res += "#";

        for(string str : strs) {
            res += str;
        }

        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        vector<int> lengths;

        int i = 0;
        while(s[i] != '#') {
            string lenStr = "";
            while(s[i] != ',' && s[i] != '#') {
                lenStr += s[i];
                i++;
            }
            int len = stoi(lenStr);
            lengths.push_back(len);
            if(s[i] == '#') {
                break;
            }
            i++;
        }

        i++; //move one ahead of #

        for(int j = 0; j < lengths.size(); j++) {
            string str = s.substr(i, lengths[j]);
            res.push_back(str);
            i = lengths[j] + i;
        }

        return res;
    }
};
