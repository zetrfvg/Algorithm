/*
枚举所有元素x∈[lo,hi]，求其权值，排序后返回第k个元素即可
*/
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        function<int(int)> calc=[&](int x){
            if(x==1) return 0;
            if(x&1) return calc(x*3+1)+1;
            else return calc(x/2)+1;
        };
        vector<vector<int>> g;
        for(int i=lo;i<=hi;i++){
            g.push_back({calc(i),i});
        }
        sort(g.begin(),g.end());
        return g[k-1][1];
    }
};
