class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(numSet.find(nums[i]-1)==numSet.end()){
                int len = 1;
                while(numSet.find(nums[i]+len) != numSet.end()){
                    len++;
                }
                ans = max(len,ans);
            }
        }
        return ans;
    }
};
