class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int i, vector<int>& cur){
        res.push_back(cur);
        for(int j=i;j<nums.size();j++){
            cur.push_back(nums[j]);
            backtrack(nums,j+1,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(nums,0,cur);
        return res;
    }
};
