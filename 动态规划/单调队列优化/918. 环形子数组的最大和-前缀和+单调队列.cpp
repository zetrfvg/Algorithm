/*
1、破环成链，将nums[0]~nums[n-1]依次加到nums[n]~nums[2n-1]中，对这个长度2n的数组求解即可。
2、把nums转换成它的前缀和数组
3、考虑区间和为nums[j]-nums[i]，作为答案，我们希望nums[j]尽可能的大，nums[i]尽可能的小，并且这里0 <= (j-i) <= n
4、用一个单调队列来维护一个递增的序列
   枚举到第j个元素时，如果队头元素i与j之间相差的距离大于n，则弹出队头元素
   此时队头元素i即为j对应能到能取到的最小元素，用nums[j]-nums[i]来更新答案
   弹出队尾所有大于等nums[j]的元素，再将j入队，以保证队列的单调性
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        for(int i=1;i<2*n;i++) nums[i]+=nums[i-1];
        deque<int> q;
        for(int i=0;i<2*n;i++){
            if(!q.empty()&&i-q.front()>n) q.pop_front();
            if(!q.empty()) ans=max(ans,nums[i]-nums[q.front()]);
            while(!q.empty()&&nums[q.back()]>nums[i]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
