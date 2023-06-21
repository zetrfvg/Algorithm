/*
双指针枚举右端点计数
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n=prices.size();
        for(int l=0,r=0;r<n;r++){
            if(l!=r&&prices[r]!=prices[r-1]-1) l=r;
            ans+=(r-l+1);
        }
        return ans;
    }
};
