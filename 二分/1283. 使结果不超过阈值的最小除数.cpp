/*
二分答案，合法则缩上界，不合法则缩下界
*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1e9;
        while(l<r){
            int m=(l+r)>>1;
            long long sum=0;
            for(auto c:nums) sum+=(c+m-1)/m;
            if(sum<=threshold) r=m;
            else l=m+1;
        }
        return l;
    }
};
