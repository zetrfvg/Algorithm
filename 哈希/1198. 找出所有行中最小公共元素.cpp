/*
每一行严格递增，即每行不存在重复元素
因此用哈希表找到出现次数为n的最小元素即可
*/
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> p;
        for(auto v:mat){
            for(auto c:v){
                p[c]++;
            }
        }
        for(auto [x,y]:p) if(y==mat.size()) return x;
        return -1;
    }
};
