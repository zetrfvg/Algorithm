/*
对于arr排序后的数组cpy，如果[l,r]中的各个元素在两个数组中的频次相同，说明[l,r]可以被分为一个块
基于这点，用哈希表来维护频次即可
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> g;
        int ans=0;
        int up=0,down=0;
        auto cpy=arr;
        sort(cpy.begin(),cpy.end());
        for(int i=0;i<n;i++){
            if(!g[arr[i]]++) up++;
            if(!g[arr[i]]) down--;
            if(!g[cpy[i]]--) down++;
            if(!g[cpy[i]]) up--;
            ans+=(!up&&!down);
        }
        return ans;
    }
};
