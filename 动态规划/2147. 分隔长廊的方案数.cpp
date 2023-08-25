/*
每连续两个座椅视为一个整体，枚举出各个整体之间有多少个隔板可以插入进行分隔，依乘法原理累计答案即可
*/
class Solution {
public:
    int numberOfWays(string corridor) {
        if(count(corridor.begin(),corridor.end(),'S')&1) return 0;
        if(count(corridor.begin(),corridor.end(),'S')==0) return 0;
        int n=corridor.size();
        const int mod=1e9+7;
        vector<int> p;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S') p.push_back(i);
        }
        int ans=1;
        for(int i=2;i<p.size();i+=2){
            ans=1LL*(p[i]-p[i-1])*ans%mod;
        }
        return ans;
    }
};
