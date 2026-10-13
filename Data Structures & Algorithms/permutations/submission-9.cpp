class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> used(nums.size(),false);
        backtrack(nums,cur,used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, vector<bool>& used){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int j=0;j<nums.size();j++){
            if(used[j]) continue;
            cur.push_back(nums[j]);
            used[j] = true;
            backtrack(nums,cur,used);
            cur.pop_back();
            used[j] = false;
        }
    }
};
