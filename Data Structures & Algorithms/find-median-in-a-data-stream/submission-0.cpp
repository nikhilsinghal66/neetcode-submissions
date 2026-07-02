class MedianFinder {
public:
    vector<int> median;
    MedianFinder() {
    }
    void addNum(int num) {
        median.push_back(num);
        
    }
    double findMedian() {
        long long n=median.size();
        sort(median.begin(),median.end());
        if(n%2==0){
            long long num1=median[n/2];
            long long num2=median[(n/2)-1];
            return (num1+num2)/2.0;
        }
        else{
            return median[n/2];
        }
    }
};
