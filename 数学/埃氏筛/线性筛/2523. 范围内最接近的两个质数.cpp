/*
线性筛筛出所有质数，枚举[left,right]内的合法质数对即可
*/
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> p,vis(1000010);
        for(int i=2;i<=right;i++){
            if(!vis[i]) p.push_back(i);
            for(int j=0;1LL*i*p[j]<=right;j++){
                vis[i*p[j]]=1;
                if(i%p[j]==0) break;
            }
        }
        int L=1e9;
        vector<int> ans(2,-1);
        for(int i=1;i<p.size();i++){
            int x=p[i-1],y=p[i];
            if(x>=left&&x<=right&&y>=left&&y<=right){
                if(y-x<L){
                    L=y-x;
                    ans={x,y};
                }
            }
        }
        return ans;
    }
};
