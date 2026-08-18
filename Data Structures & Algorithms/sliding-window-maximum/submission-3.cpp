class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);
        deque<int> dq;

        int l = 0, r = 0;

        while(r < nums.size()) {

            // Remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);

            // Remove indices outside the window
            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }

            // Window has reached size k
            if(r + 1 >= k){
                res[l] = nums[dq.front()];
                l++;
            }

            r++;
        }

        return res;
    }
};