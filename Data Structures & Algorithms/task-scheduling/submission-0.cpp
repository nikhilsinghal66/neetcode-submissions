class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]){
                pq.push(freq[i]);
            }
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                auto temp=pq.top();
                pq.pop();
                int cnt=temp-1;
                if(cnt>0){
                    q.push({cnt,time+n+1});
                }
            }
        }
        return time;
    }
};
