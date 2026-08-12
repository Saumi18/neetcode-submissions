class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++){
            vector<int> count(26,0);
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }
            string key ="";
            for(int i=0;i<26;i++){
                key += to_string(count[i]) + ",";
            }
            mp[key].push_back(strs[i]);
            //we cant use mp[key] = strs[i] as it will overwrite instead of taking all
        }
        for(auto& pair : mp){
            result.push_back(pair.second);
        }
        return result;
    }
};
