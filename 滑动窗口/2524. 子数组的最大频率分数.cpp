/*
用一个数组来记录插入元素nums[r]时，其幂次是多少
剩下的用滑窗模拟即可
*/
class Solution {
public:
    static const int mod=1e9+7;
    int maxFrequencyScore(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> p;
        int ans=0,s=0;
        for(int l=0,r=0;r<nums.size();r++){
            auto &a=p[nums[r]];
            if(a.size()){
                s=((s-a.back())%mod+mod)%mod;
                a.push_back(1LL*a.back()*nums[r]%mod);
            }else{
                a.push_back(nums[r]);
            }
            s=(1LL*s+a.back())%mod;
            if(r>=k-1){
                ans=max(ans,s);
                auto &b=p[nums[l]];
                s=((s-b.back())%mod+mod)%mod;
                b.pop_back();
                if(b.size()) s=(1LL*s+b.back())%mod;
                l++;
            }
        }
        return ans;
    }
};
