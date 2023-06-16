/*
状态定义：
need[i]：学完集合为i的课程，所需要的先修课程
dp[i]：学完集合为i的课程，所需要的学期
*/
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1<<n,1e9),need(1<<n);
        for(auto &re:relations){
            need[1<<(re[1]-1)]|=(1<<(re[0]-1));//初始化每个课程的先修课程
        }
        dp[0]=0;
        for(int i=1;i<(1<<n);i++){
            need[i]=need[i&(i-1)]|need[i&(-i)];//任选两个集合，使这二者的并集等于i，那么学完集合为i的课程所需的先修课程，由这二者的并递推得到
            if((need[i]|i)!=i) continue;//集合i中存在未修的先修课程，因此无法得到这个状态
            int valid=i^need[i];//集合i去掉所有的先修课程，即为这个学期要学的课程的集合，记为valid
            if(__builtin_popcount(valid)<=k){//如果valid中课程数小于等于k，说明可以一个学期学完，直接进行转移
                dp[i]=min(dp[i],dp[i^valid]+1);
            }else{
                for(int sub=valid;sub;sub=(sub-1)&valid){//如果valid中课程数大于k，则无法一个学期学完，这时要进行子集的枚举来进行状态的转移
                    if(__builtin_popcount(sub)<=k){
                        dp[i]=min(dp[i],dp[i^sub]+1);
                    }
                }
            }
        }
        return dp.back();
    }
};
