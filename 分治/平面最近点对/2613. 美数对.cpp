/*
分治+归并
*/
class Solution {
public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<array<int,3>> e(n);
        for(int i=0;i<n;i++){
            e[i]={nums1[i],nums2[i],i};
        }
        vector<int> ans(2,1e9);
        sort(e.begin(),e.end());
        for(int i=1;i<n;i++){
            if(e[i][0]==e[i-1][0]&&e[i][1]==e[i-1][1]){
                vector<int> t{e[i-1][2],e[i][2]};
                ans=min(ans,t);
            }
        }
        if(ans[0]!=1e9) return ans;
        auto dis=[&](auto &a,auto &b){
            return abs(a[0]-b[0])+abs(a[1]-b[1]);
        };
        int mx=1e9;
        function<int(int,int)> DC=[&](int l,int r)->int{
            if(l==r) return 1e9;
            int m=(l+r)>>1;
            auto tmp=e[m];
            int d=min(DC(l,m),DC(m+1,r));
            int i=l,j=m+1;
            vector<array<int,3>> b,c;
            while(i<=m&&j<=r){
                if(e[i][1]<e[j][1]) b.push_back(e[i++]);
                else b.push_back(e[j++]);
            }
            while(i<=m) b.push_back(e[i++]);
            while(j<=r) b.push_back(e[j++]);
            for(int u=l,v=0;v<b.size();u++,v++) e[u]=b[v];
            for(i=0;i<b.size();i++) if(abs(tmp[0]-b[i][0])<=d) c.push_back(b[i]);
            for(i=0;i<c.size();i++){
                for(j=i+1;j<c.size()&&c[j][1]-c[i][1]<=d;j++){
                    int x=min(c[j][2],c[i][2]),y=max(c[j][2],c[i][2]);
                    d=min(d,dis(c[i],c[j]));
                    if(dis(c[i],c[j])<mx){
                        ans={x,y};
                        mx=d;
                    }else if(dis(c[i],c[j])==mx){
                        vector<int> t{x,y};
                        ans=min(t,ans);
                    }
                }
            }
            return d;
        };
        cout<<DC(0,n-1);
        
        return ans;
    }
};
