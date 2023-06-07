/*
哈希表记录余数d的个数是否和余数k-d的相等即可
*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> g;
        int n=arr.size();
        for(auto c:arr) if(c%k) g[((c%k)+k)%k]++;
        for(auto &[a,b]:g){
            if(a*2==k&&b&1) return false;
            if(g[k-a]!=b) return false;
        }
        return true;
    }
};
