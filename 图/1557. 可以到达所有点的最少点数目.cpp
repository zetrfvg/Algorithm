/*
整个图是一个DAG
我们只需要找到所有入度为0的点即可
*/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> to(n),ans;
        for(auto &p:edges){
            to[p[1]]=1;
        }
        for(int i=0;i<n;i++){
            if(!to[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
