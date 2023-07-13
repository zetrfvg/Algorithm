/*
对前一半的位置进行暴搜即可
*/
class Solution {
public:
    vector<vector<int>> d{{0,0},{1,1},{8,8},{6,9},{9,6}};
    vector<string> findStrobogrammatic(int n) {
        string res(n,'0');
        vector<string> ans;
        function<void(int)> dfs=[&](int pos){
            if(pos>=(n+1)/2){
                ans.push_back(res);
                return;
            }
            if(n&1&&pos==n/2){
                for(int i=0;i<3;i++){
                    res[pos]='0'+d[i][0];
                    dfs(pos+1);
                }
            }else{
                for(int i=(!pos);i<5;i++){
                    res[pos]='0'+d[i][0];
                    res[n-1-pos]='0'+d[i][1];
                    dfs(pos+1);
                }
            }
        };
        dfs(0);
        return ans;
    }
};
