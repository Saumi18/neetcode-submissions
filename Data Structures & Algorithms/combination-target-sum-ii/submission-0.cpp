class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        backtrack(candidates,cur,target,0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int target, int i){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        if(target < 0 || i>=nums.size()) return;
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j-1] == nums[j]) continue;
            if(nums[j] > target ) break;

            cur.push_back(nums[j]);
            backtrack(nums,cur,target-nums[j],j+1);
            cur.pop_back();
        }
    }
};
