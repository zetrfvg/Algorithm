/*
对于每个nums[i]，记录两个数组
up[i][k]：第i个元素右侧比k大的元素
down[i][k]：第i个元素左侧比k小的元素

对于i < j < k < l ，要满足 nums[i] < nums[k] < nums[j] < nums[l]
枚举k与j依据乘法原理，其贡献为down[j][nums[k]]*up[k][nums[j]]

*/
const int N=4e3+10;
int up[N][N],down[N][N];
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        memset(up,0,sizeof up);
        memset(down,0,sizeof down);
        for(int i=n-2;i>=2;i--){
            memcpy(up[i],up[i+1],sizeof up[i+1]);
            for(int j=nums[i+1]-1;j;j--){
                up[i][j]++;
            }
        }
        for(int i=1;i<n-2;i++){
            memcpy(down[i],down[i-1],sizeof down[i-1]);
            for(int j=nums[i-1]+1;j<=n;j++){
                down[i][j]++;
            }
        }
        long long ans=0;
        for(int i=1;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(nums[i]>nums[j]){
                    ans+=1LL*down[i][nums[j]]*up[j][nums[i]];
                }
            }
        }
        return ans;
    }
};
