/*
枚举
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(auto c:jewels) ans+=count(stones.begin(),stones.end(),c);
        return ans;
    }
};
