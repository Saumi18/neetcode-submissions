class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(),nums.end());
        backtrack(nums,cur,0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int i){
        res.push_back(cur);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j] == nums[j-1]) continue;
            cur.push_back(nums[j]);
            backtrack(nums, cur, j+1);
            cur.pop_back();
        }
    }
};
