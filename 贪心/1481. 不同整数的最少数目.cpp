/*
将元素离散化后，每次选取出现次数最少的数删除即可
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int idx=0;
        vector<int> g;
        unordered_map<int,int> p;
        for(auto d:arr){
            if(!p.count(d)){
                p[d]=idx++;
                g.push_back(0);
            }
            g[p[d]]++;
        }
        sort(g.begin(),g.end(),greater<>());
        for(int i=idx-1;~i;i--){
            if(k-g[i]<0) return i+1;
            k-=g[i];
        }
        return 0;
    }
};
