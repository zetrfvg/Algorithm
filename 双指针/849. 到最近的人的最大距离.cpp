/*
枚举连续的两个坐了人的位置，则到这两个人的距离的极大值的最小值为(r-l)/2
需要特判两边端点的距离
*/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int ans=0;
        for(int l=-1,r=0;r<n;r++){
            if(seats[r]){
                if(l!=-1) ans=max(ans,(r-l)/2);
                else ans=r;
                l=r;
            }else if(r==n-1) ans=max(ans,r-l);
        }
        return ans;
    }
};
