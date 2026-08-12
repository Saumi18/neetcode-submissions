class Solution {
public:
    bool isAnagram(string s, string t) {
        string s_new = s;
        string t_new = t;
        sort(s_new.begin(),s_new.end());
        sort(t_new.begin(),t_new.end());
        return s_new == t_new;
    }
};
