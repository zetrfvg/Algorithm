/*
每次选取最大的元素进行减半操作
*/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q(nums.begin(),nums.end());
        double sum=accumulate(nums.begin(),nums.end(),0L);
        double cur=sum;
        int ans=0;
        while(cur*2>sum){
            double x=q.top();
            q.pop();
            cur-=x;
            x/=2;
            cur+=x;
            q.push(x);
            ans++;
        }
        return ans;
    }
};
