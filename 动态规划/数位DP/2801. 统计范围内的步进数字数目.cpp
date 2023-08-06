/*
状态定义：
dp[pos][full][flag][lst]：考虑前高第pos个位置，full表示之前的位置是否都到达上限，flag表示是否有前导0，lst表示前一位放置的数字是多少
*/
class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        const int mod=1e9+7;
        int f[101][2][2][12];
        reverse(low.begin(),low.end());
        reverse(high.begin(),high.end());
        function<int(int,int,int,int,string)> dp=[&](int pos,int full,int flag,int lst,string num){
            if(pos<0){
                return flag;
            }
            if(pos>=num.size()) return dp(pos-1,full,flag,lst,num);
            if(f[pos][full][flag][lst]>=0) return f[pos][full][flag][lst];
            int &res=f[pos][full][flag][lst]=0;
            for(int i=0;i<=9;i++){
                if(full&&i>num[pos]-'0') break;
                if(lst==11){
                    int nxtfull=full&&(i==num[pos]-'0');
                    int nxtflag;
                    if(!flag&&!i) nxtflag=0;
                    else nxtflag=1;
                    res=(res+dp(pos-1,nxtfull,nxtflag,nxtflag?i:lst,num))%mod;
                }else{
                    if(abs(i-lst)!=1) continue;
                    int nxtfull=full&&(i==num[pos]-'0');
                    int nxtflag;
                    if(!flag&&!i) nxtflag=0;
                    else nxtflag=1;
                    res=(res+dp(pos-1,nxtfull,nxtflag,i,num))%mod;
                }
            }
            return res;
        };
        memset(f,-1,sizeof f);
        long long r=dp(100,1,0,11,high);
        memset(f,-1,sizeof f);
        long long l=dp(100,1,0,11,low);
        bool ok=1;
        for(int i=1;i<low.size();i++){
            if(abs(low[i]-low[i-1])!=1) ok=0;
        }
        if(ok) r++;
        return ((r-l)%mod+mod)%mod;
    }
};
