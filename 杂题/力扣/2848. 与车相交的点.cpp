/*
简单题暴力模拟即可
*/
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> d(200);
        for(auto p:nums){
            for(int j=p[0];j<=p[1];j++){
                d[j]=1;
            }
        }
        return accumulate(d.begin(),d.end(),0);
    }
};
