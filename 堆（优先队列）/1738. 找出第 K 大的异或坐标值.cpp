/*
计算二位前缀异或和，套用一个小根堆来维护前k大的元素即可
*/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> p(n+1,vector<int>(m+1));
        priority_queue<int,vector<int>,greater<>> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                p[i][j]=matrix[i-1][j-1]^p[i-1][j-1]^p[i][j-1]^p[i-1][j];
                if(q.size()<k) q.push(p[i][j]);
                else if(p[i][j]>q.top()){
                    q.pop();
                    q.push(p[i][j]);
                }
            }
        }
        return q.top();
    }
};
