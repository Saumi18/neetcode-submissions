class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int l = 0;
        int r = k-1;
        bool dec = false;
        vector<int> check1(26,0);
        for(int i=0;i<k;i++){
            check1[s1[i]-'a']++;
        }
        while(r<s2.size()){
            vector<int> check2(26,0);
            for(int j=l;j<=r;j++){
                check2[s2[j]-'a']++;
            }
            if(check1 == check2){
                dec = true;
            }
            l++;
            r++;
        }
        return dec;
    }
};
