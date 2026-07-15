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
        int n=intervals.size();
        if(n==0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](Interval &a,Interval &b){
            return  a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(intervals[0].end);
        int max1=1;
        for(int i=1;i<n;i++){
            int start1=intervals[i].start;
            int end1=intervals[i].end;
            while(!q.empty() && q.top()<=start1){
                q.pop();
            }
            if(start1<q.top()){
                q.push(end1);
                if(q.size()>max1){
                    max1=q.size();
                }
            }
            else{
                q.push(end1);
            }
        }
        return max1;
    }
};
