class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mapS,mapT;
        for(int i=0;i<s.length();++i){
            mapS[s[i]]++;
        }
        for(int i=0;i<t.length();++i){
            mapT[t[i]]++;
        }
        return mapT == mapS;
    }
};
