class Solution {
public:
    int countTime(string time) {
        auto check=[&](int x,int y){
            return x==y||y=='?';
        };
        int ans=0;
        for(int i=0;i<24;i++){
            for(int j=0;j<60;j++){
                int a=i/10+'0';
                int b=i%10+'0';
                int c=j/10+'0';
                int d=j%10+'0';
                if(check(a,time[0])&&check(b,time[1])&&check(c,time[3])&&check(d,time[4])) ans++;
            }
        }
        return ans;
    }
};
