/*
状态定义：
dp[i][full][flag][last]：
考虑前i高个位置，full表示这些位置是否都到达上限，flag表示是否有前导0，last表示上一位填的是0还是1

*/
class Solution {
public:
    int f[31][2][2][2];
    int n;
    int dp(int pos,int full,int flag,int last){
        if(pos<0) return flag;
        if(f[pos][full][flag][last]>=0){
            return f[pos][full][flag][last];
        }
        int &res=f[pos][full][flag][last]=0;
        for(int i=0;i<2;i++){
            int j=(n>>pos)&1;
            if(last&&i) continue;//连续填两个1，不可行直接继续
            if(full){
                if(i>j) break;//填的数超过了n的上限
            }
            int nxtfull=full&&(i==j);
            int nxtflag,nxtlast;
            if(!flag&&!i){//都为前导0的情况
                nxtflag=nxtlast=0;
            }else{
                nxtflag=1;
                nxtlast=i;
            }
            res+=dp(pos-1,nxtfull,nxtflag,nxtlast);
        }
        return res;
    }
    int findIntegers(int n) {
        memset(f,-1,sizeof f);
        this->n=n;
        return dp(30,1,0,0)+1;//0是满足要求的数，要特判加上它
    }
};
