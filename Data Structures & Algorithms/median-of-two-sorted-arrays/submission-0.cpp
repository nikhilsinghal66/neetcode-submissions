class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        //Median of two sorted arrays...
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        long long low=0;
        long long high=n;
        while(low<=high){
            long long x=low+(high-low)/2;
            long long y=(n+m+1)/2 - x;
            long long l1=INT_MIN;
            long long l2=INT_MIN;
            long long r1=INT_MAX;
            long long r2=INT_MAX;
            if(x>0) l1=nums1[x-1];
            if(y>0) l2=nums2[y-1];
            if(x<n) r1=nums1[x];
            if(y<m) r2=nums2[y];
            long long maxleft=max(l1,l2);
            long long minright=min(r1,r2);
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (maxleft+minright)/2.0;
                }
                return maxleft;
            }
            if(l1>r2){
                high=x-1;
            }
            else{
                low=x+1;
            }
        }
        return -1;
    }
};
