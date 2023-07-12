/*
滑窗模拟即可
*/
class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int,int> p;
        int n=candies.size();
        for(auto c:candies) p[c]++;
        int cnt=p.size(),ans=0;
        if(!k) return cnt;
        for(int l=0,r=0;r<n;r++){
            cnt-=!--p[candies[r]];
            if(r>=k-1){
                ans=max(ans,cnt);
                cnt+=!p[candies[l++]]++;
            }
        }
        return ans;
    }
};
