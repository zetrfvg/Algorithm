/*
二分答案后双指针判定
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size(),m=heaters.size();
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int l=0,r=1e9;
        auto check=[&](int mid){
            for(int l=0,r=0;l<n||r<m;){
                if(r==m) return false;
                if(l==n) return true;
                int left=heaters[r]-mid,right=heaters[r]+mid;
                if(houses[l]>=left&&houses[l]<=right) l++;
                else r++;
            }
            return true;
        };
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
