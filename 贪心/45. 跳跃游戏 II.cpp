/*
维护一个最远可以抵达的距离，维护一个走k步最远能够到达的点
贪心的更新即可
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0,mxpos=0,end=0;
        for(int i=0;i<n-1;i++){
            mxpos=max(mxpos,i+nums[i]);
            if(i==end){
                end=mxpos;
                ans++;
            }
        }
        return ans;
    }
};
