class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> subMap;
        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(subMap.count(diff)){
                return {subMap[diff], i}; // subMap[diff] gives 2nd part of map which is the index
            }
            subMap.insert({nums[i],i});
        }
        return {};
    }
};
