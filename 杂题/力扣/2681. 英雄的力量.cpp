/*
贡献法-推式子
*/
class Solution {
public:
    static const int mod=1e9+7;
    int sumOfPower(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<>());
        long long s=0,p=1;
        for(int i=1;i<n;i++){
            s=(s+1LL*p*nums[i])%mod;
            p=(p*2LL)%mod;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+((1LL*nums[i]*nums[i])%mod)*(1LL*s+nums[i])%mod)%mod;
            if(i!=n-1){
                s-=nums[i+1];
                if(s&1) s+=mod;
                s=(s/2)%mod;
            }
        }
        return ans;
    }
};
