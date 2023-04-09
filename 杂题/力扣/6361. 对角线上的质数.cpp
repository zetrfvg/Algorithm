/*
模拟判断即可
*/
class Solution {
public:
    int diagonalPrime(vector<vector<int>>& a) {
        int n=a.size();
        int ans=0;
        auto check=[&](int x){
            if(x==1) return false;
            for(int i=2;i*i<=x;i++){
                if(x%i==0) return false;
            }
            return true;
        };
        for(int i=0;i<n;i++){
            if(check(a[i][i])) ans=max(a[i][i],ans); 
            if(check(a[i][n-i-1])) ans=max(ans,a[i][n-i-1]);
        }
        return ans;
    }
};
