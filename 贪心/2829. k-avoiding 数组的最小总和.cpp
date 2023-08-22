/*
哈希表记录之前枚举过的数
从1开始枚举，基于贪心，能加入数组则加入数组，枚举的数合法性用哈希表中元素判断
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> f(100);
        int ans=0;
        for(int i=1,j=0;j<n;i++){
            if(k-i>0&&f[k-i]) continue;
            f[i]=1;
            ans+=i;
            j++;
        }
        return ans;
    }
};
