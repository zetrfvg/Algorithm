/*
将items按价格升序排序后，处理出items的前缀中美丽值的最大值，然后在items上二分找到符合要求的价格即可
*/
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size(),q=queries.size();
        sort(items.begin(),items.end(),[](const auto &a,const auto &b){
            return a[0]<b[0];
        });
        vector<int> ans;
        for(int i=1;i<n;i++) items[i][1]=max(items[i][1],items[i-1][1]);
        for(auto &q:queries){
            if(q<items[0][0]){
                ans.push_back(0);
                continue;
            }
            int l=0,r=n-1;
            while(l<r){
                int m=(l+r+1)>>1;
                if(items[m][0]<=q) l=m;
                else r=m-1;
            }
            ans.push_back(items[l][1]);
        }
        return ans;
    }
};
