/*
记多出来的石头，其位置排列为p1,p2···
记还没有石头的位置的排列为a
对于p排列固定，枚举出a的全排列来对应放石头，枚举出a所有排列中，和p一一对应放石头的最小代价即可
*/
class Solution {
public:
    int minimumMoves(vector<vector<int>>& gird) {
        int n=9;
        vector<int> p;
        vector<array<int,2>> a;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!gird[i][j]) p.push_back(i*3+j);
                else if(gird[i][j]>1) a.push_back({gird[i][j]-1,i*3+j});
            }
        }
        int ans=1e9;
        do{
            auto b=a;
            int res=0;
            for(int i=0,j=0;i<p.size();i++){
                int sx=p[i]/3,sy=p[i]%3;
                int fx=b[j][1]/3,fy=b[j][1]%3;
                res+=abs(sx-fx)+abs(sy-fy);
                if(!--b[j][0]) j++;
            }
            ans=min(ans,res);
        }while(next_permutation(p.begin(),p.end()));
        return ans;
    }
};
