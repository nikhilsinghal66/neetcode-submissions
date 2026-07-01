class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(!pq.empty()){
            int stone1=pq.top();
            pq.pop();
            if(pq.empty()){
                return stone1;
            }
            int stone2=pq.top();
            pq.pop();
            if(stone1==stone2){
                continue;
            }
            if(stone1<stone2){
                pq.push(stone2-stone1);
            }
            else{
                pq.push(stone1-stone2);
            }
        }
        return 0;
    }
};
