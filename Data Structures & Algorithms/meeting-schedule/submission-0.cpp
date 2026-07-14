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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return a.start<b.start;
        });
        Interval temp=intervals[0];
        for(int i=1;i<n;i++){
            int start=intervals[i].start;
            int end=intervals[i].end;
            if(start<temp.end){
                return false;
            }
            else{
                temp=intervals[i];
            }
        }
        return true;
        
    }
};
