/*
求[l,r]之间合法的数字，等于求[0,r]的合法数字的个数减去[0,l-1]的合法数字的个数
状态定义：
dp[pos][full][flag][sum]：对数位由高到低考虑，当前枚举到第pos位，full表示之前枚举的数位是否已达上界，flag表示是否为前导0，sum表示已经枚举过的数位上的数字和
*/
class Solution {
public:
    static const int mod=1e9+7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n=num1.size(),m=num2.size();
        int f[23][2][2][410];
        reverse(num2.begin(),num2.end());
        reverse(num1.begin(),num1.end());
        num1[0]--;
        function<int(int,int,int,string,int)> dp=[&](int pos,int full,int flag,string s,int sum){
            if(sum>max_sum) return 0;
            if(pos<0){
                if(sum>=min_sum&&sum<=max_sum) return 1;
                else return 0;
            }
            if(pos>=s.size()) return dp(pos-1,full,flag,s,sum);
            if(f[pos][full][flag][sum]>=0) return f[pos][full][flag][sum];
            int &res=f[pos][full][flag][sum]=0;
            for(int j=0;j<=9;j++){
                if(full&&j>s[pos]-'0') break;
                int nxtfull=full&&(j==s[pos]-'0');
                int nxtflag;
                if(!flag&&!j) nxtflag=0;
                else nxtflag=1;
                res=(1LL*res+dp(pos-1,nxtfull,nxtflag,s,sum+j))%mod;
            }
            return res;
        };
        memset(f,-1,sizeof f);
        int y=dp(22,1,0,num2,0);
        memset(f,-1,sizeof f);
        int x=dp(22,1,0,num1,0);
        return (1LL*y-x+mod)%mod;
    }
};
