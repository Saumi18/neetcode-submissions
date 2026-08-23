class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0;
        vector<int> ans;
        deque<int> dq;
        while(r<nums.size()){
            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            r++;
            if(r-l == k) {
                ans.push_back(nums[dq.front()]);
                l++;
                if(nums[l-1]==nums[dq.front()]) dq.pop_front();
            }
        }
        return ans;
    }
};
