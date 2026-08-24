/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int rooms = 0;
        sort(intervals.begin(),intervals.end(),[](const Interval& a, Interval& b){
            return a.start < b.start;
        });

        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto& interval : intervals){
            if(!minHeap.empty() && interval.start>=minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
