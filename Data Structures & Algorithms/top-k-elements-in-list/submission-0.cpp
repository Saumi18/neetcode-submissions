class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for (auto& p : mp) {
            int number = p.first;
            int frequency = p.second;

            bucket[frequency].push_back(number);
        }
        for (int freq = nums.size(); freq >= 1; freq--) {
            for (int i = 0; i < bucket[freq].size(); i++) {
                result.push_back(bucket[freq][i]);
                if (result.size() == k) return result;
                }
            }
            return result;
        }
};
