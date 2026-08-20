class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans(queries.size(),0);
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(intervals.begin(),intervals.end());
        int i=0,j=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >minHeap;
        while(j<q.size()){
            while(i<intervals.size() && intervals[i][0]<=q[j].first){
                minHeap.push({intervals[i][1] - intervals[i][0] + 1,intervals[i][1]});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q[j].first){
                minHeap.pop();
            }
            if(minHeap.empty()){
                ans[q[j].second] = -1;
            }
            else{
                ans[q[j].second] = minHeap.top().first;
            }
            j++;
        }
        return ans;
    }
};
