/*
状态定义：
dp[i][full][flag]：
考虑前高i位个位置，full表示这些位置是否都到达上限，flag表示是否有前导0
*/
class Solution {
public:
    vector<int> num,dig;
    int f[10][2][2];
    int dp(int pos,int full,int flag){
        if(pos<0) return flag;
        if(f[pos][full][flag]>=0){
            return f[pos][full][flag];
        }
        int &res=f[pos][full][flag]=0;
        for(auto i:dig){
            if(flag&&!i) continue;
            if(full){
                if(i>num[pos]) break;
            }
            int nxtfull=full&&(num[pos]==i);
            int nxtflag,nxtlast;
            if(!flag&&!i){
                nxtflag=0;
            }else{
                nxtflag=1;
                nxtlast=i;
            }
            res+=dp(pos-1,nxtfull,nxtflag);
        }
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(f,-1,sizeof f);
        for(int i=0;i<10;n/=10,i++){
            num.push_back(n%10);
        }
        dig.push_back(0);
        for(auto s:digits){
            dig.push_back(s[0]-'0');
        }
        return dp(9,1,0);
    }
};
