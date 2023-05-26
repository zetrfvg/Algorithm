/*
最大化最小值
二分答案
*/
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int l=0,r=1e9;
        int n=position.size();
        sort(position.begin(),position.end());
        auto check=[&](int mid){
            int last=-1e9,cnt=0;
            for(int i=0;i<n;i++){
                if(position[i]-last>=mid){
                    cnt++;
                    last=position[i];
                }
            }
            return cnt>=m;
        };
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return l;
    }
};
