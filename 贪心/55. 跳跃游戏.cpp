/*
保证尽可能的走得远
遍历nums数组，维护一个可达的最远值arr
每枚举一个位置i，用nums[i]+i来更新arr
如果位置i超出的arr能到的最远距离，说明位置i不可达，而终点更不可达，此时返回false即可
如果最终arr>=n-1说明终点可达
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int arr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(arr<i) break;
            arr=max(arr,i+nums[i]);
        }
        return arr>=n-1;
    }
};
