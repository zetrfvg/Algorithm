/*
埃氏筛求质数
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> p(n,1);
        int ans=0;
        for(int i=2;i<n;i++){
            if(p[i]){
                ans++;
                for(long long j=1LL*i*i;j<n;j+=i) p[j]=0;
            }
        }
        return ans;
    }
};
