class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(int i=0;i<strs.size();i++){
            res += to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> fin;
        int i = 0;
        while(i<s.size()){
            string len = "";
            int n=0;
            while(s[i]!='#'){
                n = n * 10 + (s[i] - '0'); // instead of doing stoi(len) we can do this if stoi isnt allowed
                i++;
            }
            i++;
            string word = "";
            for(int j=0;j<n;j++){
                word += s[i];
                i++;
            }
            fin.push_back(word);
        }
        return fin;
    }
};
