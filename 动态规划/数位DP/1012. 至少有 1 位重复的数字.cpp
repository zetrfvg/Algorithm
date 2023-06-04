/*
求[1,n]中多少个数字满足至少有一位重复的数字=n-[1,n]中有多少数字不存在重复的数字
状态定义：
dp[pos][full][flag][sta]：对数位由高到低考虑，当前枚举到第pos位，full表示之前枚举的数位是否已达上界，flag表示是否为前导0，sta表示[0,9]中的各个数字是否被使用过
*/
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int m=n;
        vector<int> num;
        while(m){
            num.push_back(m%10);
            m/=10;
        }
        int f[num.size()][2][2][1<<11];
        memset(f,-1,sizeof f);
        function<int(int,int,int,int)> dp=[&](int pos,int full,int flag,int sta){
            if(pos<0) return flag;//枚举完一个数，如果全是前导0，则返回0；否则，这个数合法，返回1
            if(f[pos][full][flag][sta]>=0) return f[pos][full][flag][sta];//已经记忆化搜索过，返回答案
            int &res=f[pos][full][flag][sta]=0;
            for(int i=0;i<=9;i++){
                if(full&&i>num[pos]) break;//超过了上界，退出
                int nxtfull=full&&(i==num[pos]);
                int nxtflag=flag||i;
                if(sta&(1<<i)) continue;//这个数已经被用过了
                int nxtsta=sta|(1<<i);//更新状态
                if(!flag&&!i) nxtsta=0;//前导0则置为0
                res+=dp(pos-1,nxtfull,nxtflag,nxtsta);//记忆化搜索
            }
            return res;
        };
        return n-dp(num.size()-1,1,0,0);
    }
};
