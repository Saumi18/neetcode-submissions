class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int k = s1.size();
        int l = 0;
        int r = k-1;
        vector<int> check1(26,0);
        vector<int> check2(26,0);
        for(int i=0;i<k;i++){
            check1[s1[i]-'a']++;
        }
        for(int j=0;j<k;j++){
            check2[s2[j]-'a']++;
        }
        while(r<s2.size()){
            if(check1 == check2){
                return true;
            }
            l++;
            r++;
            check2[s2[l-1]-'a']--;
            if(r<s2.size()) check2[s2[r]-'a']++;
        }
        return false;
    }
};
