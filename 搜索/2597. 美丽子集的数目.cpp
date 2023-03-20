/*
dfs暴力搜索即可
二进制枚举过不了：
1、相比dfs，前者复杂度为2^n，后者复杂度为n*2^n
2、dfs有剪枝的优化，如果枚举的子集包括a[i]、a[j]，其中abs(a[i]-a[j])==k
  后者的会枚举包含i和j的所有子集，而前者枚举它们的一个子集就会剪枝剪掉，不会继续枚举到了
  
  本题还有O(n)复杂度的dp做法，有缘再补
*/
class Solution {
public:
    int beautifulSubsets(vector<int>& a, int k) {
        int n=a.size();
        int ans=0;
        vector<int> g(1010);
        auto dfs=[&](auto self,int x)->void{
            if(x==n){
                ans++;
                return;
            }
            if(g[max(0,a[x]-k)]||g[min(1001,a[x]+k)]){
                self(self,x+1);
            }else{
                self(self,x+1);
                g[a[x]]=1;
                self(self,x+1);
                g[a[x]]=0;
            }
        };
        dfs(dfs,0);
        return ans-1;//去掉空集
    }
};
