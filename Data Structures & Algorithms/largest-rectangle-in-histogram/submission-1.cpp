class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int areaMax = 0;
        int area = 0;
        stack<pair<int,int>> st;
        for(int i=0;i<=heights.size();i++){
            int currHeight = (i == heights.size()) ? 0 : heights[i];
            int start = i;
            while(!st.empty() && currHeight<st.top().second){
                start = st.top().first;
                area = (i-st.top().first)*(st.top().second);
                areaMax = max(areaMax,area);
                st.pop();
            }
            st.push({start,currHeight});
        }
        return areaMax;
    }
};
