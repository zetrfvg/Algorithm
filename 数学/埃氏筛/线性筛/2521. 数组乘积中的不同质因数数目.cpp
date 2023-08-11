/*
预处理质数，枚举所有元素的质因子即可
*/
class Solution {
public:
    static const int N=2e3+10;
    int vis[N];
    int prim[N];
    int cnt;

    void Euler(int n){
        for(int i=2;i<=n;i++){
            if(!vis[i]) prim[++cnt]=i;
            for(int j=1;1LL*i*prim[j]<=n;j++){
                vis[i*prim[j]]=1;
                if(i%prim[j]==0) break;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        Euler(1200);
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;prim[j]<=nums[i];j++){
                if(nums[i]%prim[j]==0) st.insert(prim[j]);
            }
        }
        return st.size();
    }
};
