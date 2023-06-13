/*
二分答案x，每次放置物品，贪心的放置max(x,quantities[i])，如果能够放置的商店数小于等于n，则说明x合法，收紧上界，否则，收紧下界
*/
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int l=1,r=*max_element(quantities.begin(),quantities.end());
        auto check=[&](int x){
            int res=0;
            for(int i=0;i<m;i++){
                res+=(quantities[i]+x-1)/x;
            }
            return res<=n;
        };
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
