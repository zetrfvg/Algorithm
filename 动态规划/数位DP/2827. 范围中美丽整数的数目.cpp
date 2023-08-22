/*
状态定义：
dp[pos][full][flag][lst][x][y]：对数位由高到低考虑，当前枚举到第pos位，full表示之前枚举的数位是否已达上界，flag表示是否为前导0，lst表示前面填的数对k的余数，x表示之前填的奇数个数，y表示之前填的偶数个数
*/
class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        low--;
        string down=to_string(low),up=to_string(high);
        reverse(down.begin(),down.end());
        reverse(up.begin(),up.end());
        int f[12][2][2][22][10][10];
        function<int(int,int,int,int,string,int,int)> dp=[&](int pos,int full,int flag,int lst,string num,int x,int y)->int{
            if(pos<0){
                return flag&&lst==0&&x==y;
            }
            if(pos>=num.size()) return dp(pos-1,full,flag,lst,num,x,y);
            if(f[pos][full][flag][lst][x][y]>=0) return f[pos][full][flag][lst][x][y];
            int &res=f[pos][full][flag][lst][x][y]=0;
            for(int i=0;i<=9;i++){
                if(full&&i>num[pos]-'0') break;
                int nxtfull=full&&(i==num[pos]-'0');//下一数的full状态
                int nxtflag=flag||i;//下一个数的flag状态
                int nxtlst=(lst*10+i)%k;//余数
                int nx=x,ny=y;
                if(i&1) nx++;
                else ny++;
                if(!nxtflag) nx=ny=0;//当前填的为前导0
                res+=dp(pos-1,nxtfull,nxtflag,nxtlst,num,nx,ny);//记忆化搜索
            }
            return res;
        };
        memset(f,-1,sizeof f);
        long long r=dp(11,1,0,0,up,0,0);
        memset(f,-1,sizeof f);
        long long l=dp(11,1,0,0,down,0,0);
        return r-l;
    }
};
