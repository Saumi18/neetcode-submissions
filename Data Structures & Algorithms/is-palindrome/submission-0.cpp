class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if((s[i]-'a' >=0 && s[i]-'a' < 26) || (s[i]-'A' >=0 && s[i]-'A' <26) || (s[i]-'0' >=0 && s[i]-'0' < 10)){
                temp += tolower(s[i]);
            }
        }
        int n = temp.size();
        for(int i=0;i<n;i++){
            if(temp[i] != temp[n-1-i]) return false;
        }
        return true;
    }
};
