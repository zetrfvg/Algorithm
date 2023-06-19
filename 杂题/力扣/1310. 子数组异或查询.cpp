/*
异或前缀和
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pre(n+1),ans;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]^arr[i];
        }
        for(auto q:queries){
            ans.push_back(pre[q[1]+1]^pre[q[0]]);
        }
        return ans;
    }
};
