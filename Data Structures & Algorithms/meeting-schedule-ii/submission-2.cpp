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
        int count =0;
        vector<int> startInt;
        vector<int> endInt;
        for(int i=0;i<intervals.size();i++){
            startInt.push_back(intervals[i].start);
            endInt.push_back(intervals[i].end);
        }
        sort(endInt.begin(),endInt.end());
        sort(startInt.begin(),startInt.end());
        int l=0,r=0;
        while(r<endInt.size() && l<startInt.size()){
            if(startInt[l] < endInt[r]){
                rooms++;
                l++;
                count=max(count,rooms);
            }
            else{
                rooms--;
                r++;
            }
        }
        return count;
    }
};
