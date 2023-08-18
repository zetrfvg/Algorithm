/*
简单模拟，翻转奇数次为1，偶数次为0
*/
class Solution {
public:
    int numberOfNodes(int n, vector<int>& queries) {
        vector<int> val(n+1);
        for(auto x:queries) val[x]^=1;
        for(int i=1;i<=n;i++){
            if(val[i]){
                if(i*2<=n) val[i*2]^=1;
                if(i*2+1<=n) val[i*2+1]^=1;
            }
        }
        return accumulate(val.begin(),val.end(),0);
    }
};
