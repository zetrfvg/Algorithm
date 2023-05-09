/*
维护三个哈希表：
r[i]：第i行还剩多少个元素
c[j]：第j列还剩多少个元素
mp[num]：num在矩阵中对应的下标

模拟即可
*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        vector<int> r(n,m),c(m,n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[g[i][j]]=i*m+j;
            }
        }
        for(int i=0;i<arr.size();i++){
            int pos=mp[arr[i]];
            int x=pos/m,y=pos%m;
            if((!--r[x])||(!--c[y])) return i;
        }
        return -1;
    }
};
