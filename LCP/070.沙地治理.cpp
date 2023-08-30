/*
找规律
https://leetcode.cn/problems/XxZZjK/solutions/1875939/zhao-gui-lu-han-jie-fa-de-zheng-ming-by-m43kf/
*/
class Solution {
public:
    vector<vector<int>> sandyLandManagement(int size) {
        vector<vector<int>> ans;
        for(int i=1;i<size;i++){
            for(int j=1;j<=i*2-1;j+=4){
                ans.push_back({i,j});
            }
        }
        ans.push_back({size,1});
        if(size>1) ans.push_back({size,size*2-1});
        for(int i=4;i<size*2-1;i+=8) ans.push_back({size,i});
        for(int i=7;i<size*2-1;i+=8) ans.push_back({size,i});
        for(int i=9;i<size*2-1;i+=8) ans.push_back({size,i});
        return ans;
    }
};
