class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans=0;
        for(auto c:coins) ans+=(c+1)/2;
        return ans;
    }
};
