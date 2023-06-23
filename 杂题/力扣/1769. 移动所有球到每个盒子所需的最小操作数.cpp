/*
简单统计前后缀
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> pre(n+2,0),suf(n+2,0),ans(n,0);
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+a;
            a+=boxes[i-1]=='1';
        }
        for(int i=n;i;i--){
            suf[i]=suf[i+1]+b;
            b+=boxes[i-1]=='1';
        }
        for(int i=1;i<=n;i++){
            ans[i-1]=pre[i]+suf[i];
        }
        return ans;
    }
};
