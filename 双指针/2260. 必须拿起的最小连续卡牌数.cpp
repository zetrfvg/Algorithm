/*
双指针枚举右端点
枚举存在能和右端点匹配上card的区间，取最小值即可
*/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> cnt;
        int ans=1e9;
        int n=cards.size();
        bool ok=0;
        for(int l=0,r=0;r<n;r++){
            ok=++cnt[cards[r]]==2;
            while(ok){
                ans=min(ans,r-l+1);
                ok=!--cnt[cards[l++]];
            }
        }
        return ans==1e9?-1:ans;
    }
};
