class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size()>1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x==y) continue;
            else if(x > y) maxHeap.push(x-y);
            else maxHeap.push(y-x);
        }
        if(maxHeap.size() == 0) return 0;
        else return maxHeap.top();
    }
};
