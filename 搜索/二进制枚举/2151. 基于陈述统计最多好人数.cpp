/*
用二进制枚举来模拟每个人是好人还是坏人
找到合法方案时，更新最多的好人数
*/
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int ans=0;
        for(int i=1;i<(1<<n);i++){
            auto check=[&](int state){
                for(int i=0;i<n;i++){
                    if(state&(1<<i)){
                        for(int j=0;j<n;j++){
                            if(i==j) continue;
                            if(statements[i][j]==0&&(state&(1<<j))) return false;
                            if(statements[i][j]==1&&!(state&(1<<j))) return false;
                        }
                    }
                }
                cout<<i<<" ";
                return true;
            };
            if(check(i)) ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};
