class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int> a(n,0);
        int ans=0;
        for(int i=0;i<logs.size();i++){
            if(!i) a[logs[i][0]]=logs[i][1];
            else a[logs[i][0]]=max(a[logs[i][0]],logs[i][1]-logs[i-1][1]);
        }
        return max_element(a.begin(),a.end())-a.begin();
    }
};
