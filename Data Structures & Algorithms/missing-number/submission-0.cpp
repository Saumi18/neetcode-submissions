class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> hsh(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            hsh[nums[i]]++;
        }
        for(int i=0;i<=nums.size();i++){
            if(hsh[i]==0) return i;
        }
    }
};
