class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mpp;
        if(hand.size()%groupSize!=0){
            return false;
        }
        for(auto x:hand){
            mpp[x]++;
        }
        for(int i=0;i<hand.size()/groupSize;i++){
            int small=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(small)==mpp.end()){
                    return false;
                }
                mpp[small]--;
                if(mpp[small]==0){
                    mpp.erase(small);
                }
                small++;
            }
        }
        return true;
    }
};
