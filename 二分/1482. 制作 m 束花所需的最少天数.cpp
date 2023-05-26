/*
二分答案
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k>n) return -1;
        int l=1,r=1e9;
        while(l<r){
            int mid=(l+r)>>1;
            int cnt=0,flo=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid) flo++;
                else flo=0;
                if(flo==k){
                    flo=0,cnt++;
                }
            }
            if(cnt>=m) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
