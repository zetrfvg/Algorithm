/*
模拟即可
*/
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=0,mx=-1;
        for(auto &d:divisors){
            int res=0;
            for(int &c:nums){
                if(c%d==0) res++;
            }
            if(res>mx){
                mx=res;
                ans=d;
            }else if(res==mx){
                ans=min(ans,d);
            }
        }
        return ans;
    }
};
