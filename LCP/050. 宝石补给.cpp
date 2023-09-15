class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(auto op:operations){
            int x=op[0],y=op[1],w=gem[x]/2;
            gem[x]-=w,gem[y]+=w;
        }
        return *max_element(gem.begin(),gem.end())-*min_element(gem.begin(),gem.end());
    }
};
