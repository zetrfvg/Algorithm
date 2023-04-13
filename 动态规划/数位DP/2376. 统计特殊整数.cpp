/*
数位DP
状态定义：
dp[i][full][flag][mask]：考虑前高i个位置，full表示这些位置是否都到达上限，flag表示是否有前导0，mask表示前i个位置选用的数的状态，如010010001表示前i个位置使用了1、5、8三个数
*/
class Solution {
public:
    int f[10][2][2][1<<10];
    vector<int> num;
    int dp(int pos,int full,int flag,int mask){
        if(pos<0) return flag;//返回结果，如果都为前导0，则返回0
        if(f[pos][full][flag][mask]>=0){
            return f[pos][full][flag][mask];//已经记忆化搜索过，直接返回
        }
        int &res=f[pos][full][flag][mask]=0;
        for(int i=0;i<10;i++){
            if(full){
                if(i>num[pos]) break;//前高i位都到上限，第i位也填到了上限就退出
            }
            int nxtfull=full&&(num[pos]==i);//新状态的前i+1位是否到达上限
            int nxtflag,nxtmask;
            if(!flag&&!i){
                nxtflag=nxtmask=0;//都是前导0的情况
            }else{
                if(mask&(1<<i)) continue;//这个数已被使用过
                nxtflag=1;//填过数了，不存在前导0
                nxtmask=mask|(1<<i);//新状态
            }
            res+=dp(pos-1,nxtfull,nxtflag,nxtmask);//累加dp结果
        }
        return res;
    }
    int countSpecialNumbers(int n) {
        for(int i=0;i<10;n/=10,i++){
            num.push_back(n%10);
        }
        memset(f,-1,sizeof f);
        return dp(9,1,0,0);//从最高位开始枚举
    }
};
