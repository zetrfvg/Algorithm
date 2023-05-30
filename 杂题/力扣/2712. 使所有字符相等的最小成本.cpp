/*
考虑s[i-1]和s[i]
如果二者不相等，那么势必要进行一次翻转操作，要么翻转前i个，要么翻转后n-i个，二者代价取最小值即可
枚举所有字符累加答案
*/
class Solution {
public:
    long long minimumCost(string s) {
        long long ans=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i-1]!=s[i]) ans+=min(i,n-i);
        }
        return ans;
    }
};
