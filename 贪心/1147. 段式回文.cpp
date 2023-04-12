/*
双指针对比左右两端的字符串，是否匹配，如果是，则答案+2
如果最终存在字符串未匹配或者text长度为奇数，答案需要
*/
class Solution {
public:
    int longestDecomposition(string text) {
        string a,b;
        int ans=0,n=text.size();
        int l=0,r=n-1;
        while(l<r){
            a+=text[l++];
            b=text[r--]+b;
            if(a==b){
                ans+=2;
                a.clear();
                b.clear();
            }
        }
        if(a.size()||n&1) ans++;
        return ans;
    }
};
