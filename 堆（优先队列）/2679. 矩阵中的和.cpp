/*
维护n个大根堆
每次从n个堆的堆顶元素选最大值累加到答案上即可
*/
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size(),m=nums[0].size();
        vector<priority_queue<int>> q(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                q[i].push(nums[i][j]);
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){
            int res=0;
            for(int i=0;i<n;i++){
                res=max(res,q[i].top());
                q[i].pop();
            }
            ans+=res;
        }
        return ans;
    }
};
