/*
枚举[0,0]到[200,200]方块中所有点，查询它们是否至少属于某一个圆即可
*/
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans=0;
        sort(circles.begin(),circles.end(),[](const auto &a,const auto &b){
            return a[2]>b[2];
        });
        for(int i=-0;i<=200;i++){
            for(int j=-0;j<=200;j++){
                for(auto &cir:circles){
                    if((cir[0]-i)*(cir[0]-i)+(cir[1]-j)*(cir[1]-j)<=cir[2]*cir[2]){
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
