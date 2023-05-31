/*
二分＋+滑窗
我们二分这个最小值mid
用滑窗枚举所有元素，及以它为中心左右半径长度不超过R的区间，如果当这个元素为中心的区间中总供电量cur不满足mid，则需要在这个区间中的某些个城市中共需要新增mid-cur个供电站
基于贪心的思想，因为前面的城市的供电量一定都满足mid，因此尽可能让后面的城市都吃到这个新增的供电量，所以我们把这mid-cur个供电站放在这个区间的右端点处即可
*/
class Solution {
public:
    long long maxPower(vector<int>& stations, int R, int K) {
        int n=stations.size();
        auto check=[&](long long m){
            int res=K;
            vector<long long> sta(stations.begin(),stations.end());
            long long cur=0;
            for(int i=0;i<R;i++) cur+=sta[i];
            for(int i=0,l=0,r=R;i<n;i++,r++){
                if(r<n) cur+=sta[r];
                if(cur<m){
                    long long delta=m-cur;
                    if(delta>res) return false;
                    res-=delta;
                    sta[min(n-1,r)]+=delta;
                    cur+=delta;
                }
                if(r-l>=2*R) cur-=sta[l++];
            }
            return true;
        };
        long long l=0,r=1e18;
        while(l<r){
            long long m=(l+r+1)>>1;
            if(check(m)) l=m;
            else r=m-1;
        }
        return l;
    }
};
