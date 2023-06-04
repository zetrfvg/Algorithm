/*
状态定义：
dp[pos][full][flag][sta]：对数位由高到低考虑，当前枚举到第pos位，full表示之前枚举的数位是否已达上界，flag表示是否为前导0，sta表示各个位置上是否放置的是1
*/
class Solution {
public:
    int countDigitOne(int n) {
        vector<int> num;
        while(n){
            num.push_back(n%10);
            n/=10;
        }
        int f[num.size()][2][2][1<<10];
        memset(f,-1,sizeof f);
        function<int(int,int,int,int)> dp=[&](int pos,int full,int flag,int sta){
            if(pos<0) return __builtin_popcount(sta);//枚举完了一个数位，返回其中1的个数
            if(f[pos][full][flag][sta]>=0) return f[pos][full][flag][sta];//已经记忆化搜索过，返回答案
            int &res=f[pos][full][flag][sta]=0;
            for(int i=0;i<=9;i++){
                if(full&&i>num[pos]) break;//超过了上界，退出
                int nxtfull=full&&(i==num[pos]);//下一数的full状态
                int nxtflag=flag||i;//下一个数的flag状态
                int nxtsta=sta|((i==1)<<pos);//第pos位是否放置的是1，更新状态
                res+=dp(pos-1,nxtfull,nxtflag,nxtsta);//记忆化搜索
            }
            return res;
        };
        return dp(num.size()-1,1,0,0);
    }
};
