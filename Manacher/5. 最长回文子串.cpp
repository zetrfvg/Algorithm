/*
Manacher算法
状态定义：
p[i]：以第i个字符为回文中心的最长回文半径
在枚举以各个点为回文中心的同时，维护一个向右能够覆盖到最远的回文中心M，其回文半径文R
接下来枚举第i个点为回文中心，分情况讨论：
1、i>R时，p[i]=1，并向两边暴力扩展
2、i<=R时，其关于M的对称点为2*M-i,如果p[2*M-i]<R-i+1，则令p[i]=p[2*M-i]
3、i<=R时，其关于M的对称点为2*M-i,如果p[2*M-i]>=R-i+1，先令p[i]=p[2*M-i]，然后暴力扩展
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<int> p(2*n+2);
        vector<char> t(2*n+2);
        int idx=0;
        t[++idx]='#';
        for(int i=0;i<n;i++){
            t[++idx]=s[i];
            t[++idx]='#';
        }
        int M=0,R=0;
        int j=0;
        for(int i=1;i<=idx;i++){
            if(i>R) p[i]=1;
            else p[i]=min(p[2*M-i],R-i+1);
            while(i-p[i]>=1&&i+p[i]<=idx&&t[i-p[i]]==t[i+p[i]]) p[i]++;
            if(i+p[i]-1>R){
                M=i;
                R=i+p[i]-1;
            }
            if(p[i]>p[j]) j=i;
        }
        string ans;
        for(int i=j-p[j]+1;i<=j+p[j]-1;i++){
            if(t[i]!='#') ans+=t[i];
        }
        return ans;
    }
};
