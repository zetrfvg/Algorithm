class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<int> ids(n);
        vector<string> ans(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](const auto &a,const auto &b){
            return heights[a]>heights[b];
        });
        for(int i=0;i<n;i++){
            ans[i]=names[ids[i]];
        }
        return ans;
    }
};
