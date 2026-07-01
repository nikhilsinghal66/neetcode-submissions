class Solution {
public:
    bool f(int k,vector<int> &piles,int h){
        if (k == 0) return false;
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            // ans+=(piles[i] + k - 1LL) / k;
            ans+=ceil((double)piles[i]/(double)k);
        }
        return ans<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(h<n){
            return -1;
        }
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            bool check=f(mid,piles,h);
            if(check){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
