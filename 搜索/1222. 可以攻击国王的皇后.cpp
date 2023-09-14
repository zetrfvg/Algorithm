/*
注意到所有棋子左边不超过10，因此对king所在位置的八个方向暴力搜索即可
*/
class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        set<vector<int>> st(queens.begin(),queens.end());
        for(int i=0;i<8;i++){
            int step=10,x=king[0]+dx[i],y=king[1]+dy[i];
            while(step--){
                if(st.count({x,y})){
                    ans.push_back({x,y});
                    break;
                }
                x+=dx[i],y+=dy[i];
            }
        }
        return ans;
        
    }
};
