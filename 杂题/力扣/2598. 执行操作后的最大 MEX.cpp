/*
由题意不难想到同余的性质
把nums中所有元素对value取余映射为[0,value-1]这个区间中的数
并用一个哈希表来维护区间[0,value-1]中各个元素的个数
依次枚举mex，如果枚举mex中i是否存在，则只需要查询哈希表中是否还存在i%value的元素
如果存在，则继续向下枚举i+1，同时哈希表中i%value的元素减少一个
直到哈希表中不存在i%value的元素为止
*/
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value){
        int n=nums.size();
        for(auto &c:nums) c=(c%value+value)%value;
        unordered_map<int,int> g;
        for(auto c:nums) g[c]++;
        for(int i=0;i<n;i++){
            if(g[i%value]) g[i%value]--;
            else return i;
        }
        return n;
    }
};
