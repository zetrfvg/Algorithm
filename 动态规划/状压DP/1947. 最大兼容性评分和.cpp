/*
状态定义：
dp[i]：i表示选哪些老师，i中1的个数cnt表示选到了第cnt个学生，枚举i中1个位置即枚举选到的老师，计算每个老师和第cnt个学生的兼容性评分进行转移
转移方程：
dp[i]=max(dp[i],dp[i^(1<<j)]+calc(__builtin_popcount(i)-1,j))
*/
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        int m=students[0].size();
        auto calc=[&](int i,int j){
            int res=0;
            for(int k=0;k<m;k++){
                res+=students[i][k]==mentors[j][k];
            }
            return res;
        };
        int dp[1<<n];
        for(int i=0;i<(1<<n);i++){
            dp[i]=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    dp[i]=max(dp[i],dp[i^(1<<j)]+calc(__builtin_popcount(i)-1,j));
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
