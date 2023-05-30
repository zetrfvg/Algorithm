/*
用一个单调递减的队列来维护这个滑动窗口内的k个元素
首先枚举所有元素，当当前元素到队头元素的距离超过了k，则弹出队头元素
其次，队尾元素如果小于当前元素，也弹出
之后，把当前元素入队
此时队头元素就是这个滑动窗口内的最大值
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty()&&i-q.front()>=k) q.pop_front();
            while(!q.empty()&&nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
