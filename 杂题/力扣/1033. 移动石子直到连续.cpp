/*
简单分类讨论即可
*/
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x=min({a,b,c});
        int z=max({a,b,c});
        int y=a+b+c-x-z;
        vector<int> ans(2,2);
        ans[1]=z-x-2;
        if(z-y==1&&y-x==1) ans[0]=0;
        else if(z-y<=2||y-x<=2) ans[0]=1;
        return ans;
    }
};
