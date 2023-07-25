/*
回文串中我们只关心每个字符出现个数的奇偶性，回文串有以下两种情形：
1、字符个数都为偶数
2、仅存在一个字符的个数为奇数，其余为偶数
基于奇偶性，我们用异或数来表示某条路径上的字符奇偶性状态
预处理出各个点到根结点的异或和
对于两个点x,y之间的路径异或和，可以用x到根的路径异或上y到根的路径
用哈希表来统计之前有多少个路径能够和当前枚举的点构成回文路径
*/
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>> e(n);
        for(int i=1;i<n;i++){
            e[parent[i]].push_back(i);
        }
        long long ans=0;
        unordered_map<int,long long> cnt;
        function<void(int,int)> dfs=[&](int x,int msk){
            for(int i=0;i<26;i++){
                if(cnt.count(msk^(1<<i))) ans+=cnt[msk^(1<<i)];
            }
            ans+=cnt[msk]++;
            for(auto y:e[x]){
                dfs(y,msk^(1<<(s[y]-'a')));
            }
        };
        dfs(0,0);
        return ans;
    }
};
