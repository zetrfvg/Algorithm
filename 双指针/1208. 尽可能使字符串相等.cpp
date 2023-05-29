/*
双指针枚举右端点，当当前枚举的区间中的代价超过maxCost时，移动左指针
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0;
        int n=s.size();
        int cost=0;
        for(int l=0,r=0;r<n;r++){
            cost+=abs(s[r]-t[r]);
            while(cost>maxCost){
                cost-=abs(s[l]-t[l++]);
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
