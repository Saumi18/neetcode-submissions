class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = 0;
        unordered_set<char> check;
        int l=0;
        for(int i=0;i<s.size();i++){
            while(check.count(s[i])){
                check.erase(s[l]);
                l++;
            }
            check.insert(s[i]);
            len = check.size();
            res = max(len,res);
        }
        return res;
    }
};
