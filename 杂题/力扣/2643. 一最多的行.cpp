/*
模拟即可
*/
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mx=0,r=0;
        for(int i=0;i<mat.size();i++){
            int t=0;
            for(auto &c:mat[i]){
                t+=c&1;
            }
            if(t>mx){
                mx=t;
                r=i;
            }
        }
        return {r,mx};
    }
};
