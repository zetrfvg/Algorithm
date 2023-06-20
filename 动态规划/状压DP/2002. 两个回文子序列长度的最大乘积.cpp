/*
记选出来的回文串为a,b
首先二进制枚举所有的回文串a，这时a的子集记作i
则我们需要从(1<<n)-1对于i的补集中选出回文串b
因此枚举((1<<n)-1)^i的子集，如果选出的b是回文的则更新答案
这样可以枚举出所有两个不相交的回文串
*/
class Solution {
public:
    int maxProduct(string s) {
        int n=s.size();
        int all=(1<<n)-1;
        auto check=[](string s){
            for(int l=0,r=s.size()-1;l<r;l++,r--){
                if(s[l]!=s[r]) return false;
            }
            return true;
        };
        int ans=0;
        for(int i=1;i<(1<<n);i++){
            string a;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) a+=s[j];
            }
            if(!check(a)) continue;
            int m=all^i;
            for(int j=m;j;j=(j-1)&m){
                string b;
                for(int k=0;k<n;k++){
                    if(j&(1<<k)) b+=s[k];
                }
                int res=a.size()*b.size();
                if(check(b)) ans=max(ans,res);
            }
        }
        return ans;
    }
};
