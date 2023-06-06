/*
对数组排序，最小的元素一定是lower[0]，我们枚举后续的元素作为high[0]，则有high[0]-lower[0]==2*k
然后对剩下的元素双指针枚举是否能够两两配对成功即可
*/
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            ans.clear();
            int k=nums[i]-nums[0];
            if(k&1||!k) continue;
            ans.push_back(nums[0]+k/2);
            vector<int> vis(n);
            vis[0]=vis[i]=1;
            int l=0;
            while(l<n&&vis[l]) l++;
            int r=l+1;
            while(r<n&&vis[r]) r++;
            while(r<n){
                if(nums[r]-nums[l]>k) break;
                else if(nums[r]-nums[l]==k){
                    ans.push_back(nums[l]+k/2);
                    vis[l]=vis[r]=1;
                }else r++;
                while(r<n&&vis[r]) r++;
                while(l<n&&vis[l]) l++;
            }
            if(ans.size()==n/2) return ans;
        }
        return {};
    }
};
