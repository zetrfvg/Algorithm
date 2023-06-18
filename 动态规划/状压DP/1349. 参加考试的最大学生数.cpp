/*
dp[i][j]：
考虑前i排座位，第i排学生状态为j的最多的学生数
*/
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size(),m=seats[0].size();
        vector<int> st;
        for(int i=0;i<(1<<m);i++){
            if(!(i&(i>>1))) st.push_back(i);//预处理出没有相邻的1的所有二进制数
        }
        vector<int> seat(n);//记录每一排的障碍物在哪些位置上
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=0;j<m;j++){
                if(seats[i][j]=='#') t|=(1<<j);
            }
            seat[i]=t;
        }
        vector<unordered_map<int,int>> dp(n+1);
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(auto j:st){//枚举第i排的状态
                if(j&seat[i-1]) continue;//学生座位和该排障碍物重合，不合法
                for(auto [jj,c]:dp[i-1]){//枚举前一排的状态
                    if(!(j&(jj<<1))&&!(j&(jj>>1))){//前一排的学生即没有左上的，也没有右上的
                        dp[i][j]=max(dp[i][j],c+__builtin_popcount(j));//状态转移
                    }
                }

            }
        }
        int ans=0;
        for(auto [a,b]:dp[n]) ans=max(ans,b);//枚举最后一排状态的最大值
        return ans;
    }
};
