class Solution {
public:
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
    int commonFactors(int a, int b) {
        int g=gcd(a,b),ans=0;
        for(int i=1;i*i<=g;i++){
            if(g%i==0){
                ans+=2;
                if(i*i==g) ans--;
            }
        }
        return ans;
    }
};
