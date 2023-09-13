/*
状态定义dp[i]：是否能走到第i格
枚举位置i的时候，维护一个差分数组，如果i能走到，则在i+minJump上加一个标记1，在i+maxJump+1上加一个标记-1，走到第i格把前i格的标记累加起来，如果是正数则说明该格可以走到
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int> dp(n+1),st(n+1);
        int cur=0;
        st[0]=1,st[1]=-1;
        for(int i=0;i<n;i++){
            cur+=st[i];
            if(s[i]=='1') continue;
            if(cur){
                dp[i]=1;
                st[min(i+minJump,n)]++;
                st[min(i+maxJump+1,n)]--;
            }
        }
        return dp[n-1];
    }
};
