/*
模拟，细节多要想清楚
*/
class Solution {
public:
    int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto calc=[&](string s){
            int m=(s[0]-'0')*10+s[1]-'0';
            int d=(s[3]-'0')*10+s[4]-'0';
            int res=d;
            for(int i=1;i<m;i++) res+=day[i];
            return res;
        };
        int la=calc(arriveAlice),ra=calc(leaveAlice);
        int lb=calc(arriveBob),rb=calc(leaveBob);
        if(la>lb) swap(la,lb),swap(ra,rb);
        if(lb>ra) return 0;
        else if(rb<=ra) return rb-lb+1;
        else return ra-lb+1;
    }
};
