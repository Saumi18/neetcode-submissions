class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int maxFreq = 0;
        int l=0;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq,freq[s[i]-'A']);
            while(i+1-l-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            res = max(res,i+1-l);
        }
        return res;
    }
};
