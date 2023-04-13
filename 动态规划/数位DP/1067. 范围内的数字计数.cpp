/*
状态定义：
dp[i][full][flag][cnt]：考虑前高i个位置，full表示这些位置是否都到达上限，flag表示是否有前导0，cnt表示当前有多少个d
*/
class Solution {
public:
    int f[10][2][2][10];
    vector<int> l,h;
    int d;
    int dp(int pos,int full,int flag,int cnt,vector<int>& g){
        if(pos<0) return cnt;
        if(f[pos][full][flag][cnt]>=0){
            return f[pos][full][flag][cnt];
        }
        int &res=f[pos][full][flag][cnt]=0;
        for(int i=0;i<10;i++){
            if(full){
                if(i>g[pos]) break;
            }
            int nxtfull=full&&(i==g[pos]);
            int nxtflag,nxtcnt;
            if(!flag&&!i){
                nxtflag=nxtcnt=0;
            }else{
                nxtflag=1;
                nxtcnt=cnt+(i==d);
            }
            res+=dp(pos-1,nxtfull,nxtflag,nxtcnt,g);
        }
        return res;
    }
    int digitsCount(int d, int low, int high) {
        low--;
        for(int i=0;i<10;low/=10,high/=10,i++){
            l.push_back(low%10);
            h.push_back(high%10);
        }
        this->d=d;
        int up,down;
        memset(f,-1,sizeof f);
        down=dp(9,1,0,0,l);
        memset(f,-1,sizeof f);
        up=dp(9,1,0,0,h);
        return up-down;
    }
}
