/*
对于每个元素，记录一个序列，存储该元素出现的所有位置
对于询问，查询[left,right,value]，在value对应的序列中，二分找到大于等于right的第一个位置和大于left的第一个位置，则查询的答案为两个位置之差
*/
class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> g;
    RangeFreqQuery(vector<int>& arr){
        for(int i=0;i<arr.size();i++) g[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        auto l=lower_bound(g[value].begin(),g[value].end(),left)-g[value].begin();
        auto r=upper_bound(g[value].begin(),g[value].end(),right)-g[value].begin();
        return r-l;
    }
};
