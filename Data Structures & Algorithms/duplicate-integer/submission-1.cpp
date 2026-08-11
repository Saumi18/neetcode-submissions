class Solution {
public:
    /*bool hasDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(nums.size()==s.size()){
            return false;
        }
        else return true;
    }*/
    bool hasDuplicate(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};