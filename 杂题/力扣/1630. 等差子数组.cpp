/*
对于询问区间[l,r]
首先找到区间中的最大值mx和最小值mn
则这个区间中的元素经重排之后一定是一个首末项分别为mn、mx且公差为(mx-mn)/(r-l)的序列
可以用一个哈希表或数组来维护这个序列中每个元素是否存在
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++){
            int mx=*max_element(nums.begin()+l[i],nums.begin()+r[i]+1);
            int mn=*min_element(nums.begin()+l[i],nums.begin()+r[i]+1);
            int len=r[i]-l[i],d=(mx-mn)/len;
            if((mx-mn)%len!=0){
                ans[i]=0;
                continue;
            }
            if(mx==mn){
                ans[i]=1;
                continue;
            }
            vector<int> vis(len+1);
            bool ok=1;
            for(int j=l[i];j<=r[i];j++){
                if((nums[j]-mn)%d!=0){
                    ok=0;
                    break;
                }
                if(vis[(nums[j]-mn)/d]){
                    ok=0;
                    break;
                }
                vis[(nums[j]-mn)/d]=1;
            }
            ans[i]=ok;
        }
        return ans;
    }
};
