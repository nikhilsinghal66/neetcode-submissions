class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
                int j=i;
                int cnt=0;
                int sum=0;
                while(cnt<n){
                    sum+=gas[j];
                    sum-=cost[j];
                    if(sum<0){
                        break;
                    }
                    j=(j+1)%n;
                    cnt++;
                }
                if(cnt==n){
                    return i;
                }
            }
        }
        return -1;
    }
};
