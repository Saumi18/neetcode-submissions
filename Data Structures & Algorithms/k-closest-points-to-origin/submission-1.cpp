struct compare {
    bool operator()(const pair<int,vector<int>>& a,
                    const pair<int,vector<int>>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,compare> minHeap;
        for(auto point:points){
            int dist = point[0]*point[0] + point[1]*point[1];
            minHeap.push({dist,point});
        }
        while(k!=0){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
        }
        return ans;
    }
};
