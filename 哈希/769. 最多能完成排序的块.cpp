/*
令b等于arr，再对arr排序
遍历，对于b[i]就+1，对于arr[i]就-1，当哈希表中所有元素的值都为0的时候，说明枚举过的一段元素可以进行排序，累计答案即可
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int,int> g;
        auto b=arr;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(!++g[b[i]]) g.erase(b[i]);
            if(!--g[arr[i]]) g.erase(arr[i]);
            if(!g.size()) ans++;
        }
        return ans;
    }
};
