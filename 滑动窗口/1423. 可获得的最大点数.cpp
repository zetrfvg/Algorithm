/*
从两边选k个元素，使之最大
等价于不选一个长为n-k的区间，使区间内的元素和最小
滑动窗口解决
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(n==k) return sum;
        k=n-k;
        int ans=1e9,cur=0;
        for(int l=0,r=0;r<n;r++){
            cur+=cardPoints[r];
            if(r>=k-1){
                ans=min(ans,cur);
                cur-=cardPoints[l++];
            }
        }
        return sum-ans;
    }
};
