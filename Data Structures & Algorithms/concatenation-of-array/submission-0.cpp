class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(2*n,0);
        for(int i=0;i<2*n;i++){
            if(i<n) out[i] = nums[i];
            else out[i] = nums[i-n];
        }
        return out;
    }
};