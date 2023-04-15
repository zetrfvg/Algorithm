/*
状态定义：
dp[i]：把第i本书作为某一排的一本书，向后继续摆放剩下的书，书架最小的高度
转移方程：
dp[i]=min(dp[i],dp[j+1]+h)，其中j满足[i,j]中所有书的宽度之和小于等于shelfWidth，h为[i,j]中书的最高高度
*/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1,1e9);
        dp.back()=0;
        for(int i=n-1;~i;i--){
            int h=0,w=shelfWidth;
            for(int j=i;j<n&&w>=books[j][0];j++){
                h=max(h,books[j][1]);
                dp[i]=min(dp[i],dp[j+1]+h);
                w-=books[j][0];
            }
        }
        return dp[0];
    }
};
