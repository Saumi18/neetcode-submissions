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
        int l=0,r=0;
        int rooms =0, count =0;
        vector<int> startInt,endInt;
        for(int i =0;i<intervals.size();i++){
            startInt.push_back(intervals[i].start);
            endInt.push_back(intervals[i].end);
        }
        sort(startInt.begin(),startInt.end());
        sort(endInt.begin(),endInt.end());
        while(r<endInt.size() && l<startInt.size()){
            if(startInt[l]<endInt[r]){
                rooms++;
                l++;
                count = max(rooms,count);
            }
            else{
                rooms--;
                r++;
            }
        }
        return count;
    }
};
