/*
状态定义：
dp[i][j]：前i个字符进行j次替换之后末尾元素的最小值
转移方程：
if(arr1[i]>dp[i-1][j]) dp[i][j]=min(dp[i][j],arr1[i])
if(arr2[k]>dp[i-1][j-1]) dp[i][j]=min(dp[i][j],arr2[k])
*/
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());
        int n=arr1.size(),m=arr2.size();
        vector<vector<int>> dp(n+1,vector<int>(min(n,m)+1,1e9));
        dp[0][0]=-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,m);j++){
                if(arr1[i-1]>dp[i-1][j]){
                    dp[i][j]=arr1[i-1];
                }
                if(j&&dp[i-1][j-1]!=1e9){
                    auto it=upper_bound(arr2.begin()+j-1,arr2.end(),dp[i-1][j-1]);
                    if(it!=arr2.end()){
                        dp[i][j]=min(dp[i][j],*it);
                    }
                }
                if(i==n&&dp[i][j]!=1e9){
                    return j;
                }
            }
        }
        return -1;
    }
};
