/*
模拟题
*/
class Solution {
public:
    using ll=long long;
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<ll> score(n);
        for(int i=0;i<n;i++){
            score[edges[i]]+=1LL*i;
        }
        int ans=0;
        for(int i=0;i<n;i++) if(score[i]>score[ans]) ans=i;
        return ans;
    }
};
