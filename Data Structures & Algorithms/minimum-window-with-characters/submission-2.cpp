class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size() || t.empty()) return "";
        int minLen = INT_MAX;
        string res = "";
        unordered_map<char,int> requiredFreq,windowFreq;
        for(int i =0;i<t.size();i++){
            requiredFreq[t[i]]++;
        }
        int have = 0, need = requiredFreq.size();
        int l=0;
        pair<int,int> ind;
        for(int r=0;r<s.size();r++){
            windowFreq[s[r]]++;
            if(windowFreq[s[r]]==requiredFreq[s[r]]) have++;
            while(have==need){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    ind = {l,r};
                }
                windowFreq[s[l]]--;
                if(requiredFreq[s[l]] > windowFreq[s[l]]){
                    have--;
                }
                l++;
            }
        }
        
        if(minLen == INT_MAX) return "";
        else{
            for(int i=ind.first;i<=ind.second;i++){
                res += s[i];
            }
            return res;
        }
    }
};
