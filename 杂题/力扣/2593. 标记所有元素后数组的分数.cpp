/*
很典的题，堆，排序都能做
*/
class Solution {
public:
    long long findScore(vector<int>& a) {
        long long ans=0;
        int n=a.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<n;i++) q.push({a[i],i});
        vector<int> st(n);
        while(!q.empty()){
            auto [v,idx]=q.top();
            q.pop();
            if(st[idx]) continue;
            st[idx]=st[max(0,idx-1)]=st[min(n-1,idx+1)]=1;
            ans+=1LL*v;
        }
        return ans;
    }
};
