class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() || t.empty()){
            return "";
        }

        string res = "";
        int minLen = INT_MAX;

        unordered_map<char,int> requiredFreq, windowFreq;

        for(int i = 0; i < t.size(); i++){
            requiredFreq[t[i]]++;
        }

        int have = 0, need = requiredFreq.size();
        pair<int,int> ind;
        int l=0;
        for(int r=0; r<s.length();r++){
            windowFreq[s[r]]++;
            if(requiredFreq[s[r]] && windowFreq[s[r]]== requiredFreq[s[r]]){
                have++;
            }
            while(have==need){
                if(r+1-l < minLen){
                    minLen = r+1-l;
                    ind = {l,r};
                }
                windowFreq[s[l]]--;
                if(requiredFreq[s[l]] && windowFreq[s[l]]<requiredFreq[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(minLen == INT_MAX) return "";
        else{
            for(int i = ind.first;i<ind.second+1;i++){
                res += s[i];
            }
            return res;
        }
    }
};