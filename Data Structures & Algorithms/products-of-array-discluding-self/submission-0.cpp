class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int product = 1;
        int zeroCnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroCnt++;
            if(nums[i]!=0) product *= nums[i];
        }
        if(zeroCnt>1) return vector<int> (nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(zeroCnt>0){
                if(nums[i]==0){
                    result[i] = product;
                }
                else result[i] = 0;
            }
            else{
                result[i] = product/nums[i];
            }
        }
        return result;
    }
};
