/*
暴力迭代进行质因数分解即可
*/
class Solution {
public:
    int smallestValue(int n) {
        int ans=n;
        while(1){
            int last=ans,y=0;
            for(int i=2;i*i<=ans;i++){
                while(ans%i==0){
                    y+=i;
                    ans/=i;
                }
            }
            if(ans>1) y+=ans;
            ans=y;
            if(last==y) break;
        }
        return ans;
    }
};
