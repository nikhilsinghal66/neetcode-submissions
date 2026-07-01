class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            return "";
        }
        string ans="";
        auto &check=mpp[key];
        int low=0;
        int high=check.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int check_time=check[mid].first;
            if(check_time<=timestamp){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(high<0){
            return "";
        }
        return check[high].second;
    }
};
