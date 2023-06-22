/*
因为数据量有限，枚举所有[0,0]到[50,50]矩形区域中的所有点即可
*/
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ans(2);
        int mx=0;
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                int t=0;
                for(auto p:towers){
                    int x=p[0],y=p[1],w=p[2];
                    int xx=x-i,yy=y-j;
                    if(xx*xx+yy*yy>radius*radius) continue;
                    t+=w/(1+sqrt(xx*xx+yy*yy));
                }
                if(t>mx){
                    mx=t;
                    ans={i,j};
                }
            }
        }
        return ans;
    }
};
