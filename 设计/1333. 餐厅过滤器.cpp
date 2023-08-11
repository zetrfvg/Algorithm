/*
模拟设计
*/
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> valid;
        for(auto &res:restaurants){
            if(veganFriendly&&!res[2]) continue;
            if(res[3]<=maxPrice&&res[4]<=maxDistance){
                valid.push_back(res);
            }
        }
        sort(valid.begin(),valid.end(),[&](const auto &a,const auto &b){
            return a[1]==b[1]?a[0]>b[0]:a[1]>b[1];
        });
        vector<int> ans;
        for(auto va:valid) ans.push_back(va[0]);
        return ans;
    }
};
