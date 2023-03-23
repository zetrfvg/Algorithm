/*
DP思路和LIS问题类似
只是转移方程dp[i]=max(dp[i],dp[j]+1)发生的条件不同
LIS问题时nums[j]<nums[i]时转移
该题则是x,y两个串y比x长度长1且x是y的子序列时进行转移
这里用双指针来判定这个条件
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](auto &a,auto &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(words[i].size()==words[j].size()) continue;
                else if(words[i].size()-words[j].size()>1) break;
                else{
                    auto &x=words[i],&y=words[j];
                    int c=0;
                    for(int l=0,r=0;l<x.size()&&r<y.size();){
                        if(x[l++]!=y[r++]){
                            r--;
                            c++;
                        }
                    }
                    if(c<=1) dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
