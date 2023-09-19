/*
模拟
*/
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& a, int k) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(__builtin_popcount(i)==k) ans+=a[i];
        }
        return ans;
    }
};
