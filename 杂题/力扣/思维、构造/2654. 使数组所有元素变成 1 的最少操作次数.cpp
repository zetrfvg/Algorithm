/*
找到最短的子数组[l,r]，其gcd=1，那么操作出这个1的操作数为r-l
然后这个1可以向左向右把数组元素全变为1，总操作数为n+r-l-1
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,gcd=0;
        for(int i=0;i<n;i++){
            gcd=__gcd(gcd,nums[i]);
            if(nums[i]==1) cnt++;
        }
        if(gcd!=1) return -1;
        if(cnt) return n-cnt;
        int mn=n;
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=i;j<n;j++){
                t=__gcd(t,nums[j]);
                if(t==1){
                    mn=min(mn,j-i);
                    break;
                }
            }
        }
        return n+mn-1;
    }
};
