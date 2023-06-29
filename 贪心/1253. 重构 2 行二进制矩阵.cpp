/*
colsum[i]为0或2时，则该位置的两个元素一定相同
colsum[i]为1时，我们选取剩余总和更大的那一行放1
其余无解的情况特判即可
*/
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int>> ans(2,vector<int>(n));
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                ans[0][i]=ans[1][i]=1;
                upper--,lower--;
            }else if(colsum[i]==1){
                if(upper>lower){
                    ans[0][i]=1;
                    upper--;
                }else{
                    ans[1][i]=1;
                    lower--;
                }
            }
            if(upper<0||lower<0) return {};
        }
        if(upper||lower) ans.clear();
        return ans;
    }
};
