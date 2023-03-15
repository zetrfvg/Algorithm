class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        for(int i=0;i<=rowIndex;i++){
            vector<int> t;
            for(int j=0;j<=i;j++){
                if(j==0||j==i) t.push_back(1);
                else t.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(t);
        }
        return ans.back();
    }
};
