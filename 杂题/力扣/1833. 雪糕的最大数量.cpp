/*
排序，从便宜的雪糕开始买
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(costs.begin(),costs.end());
        for(int i=0;i<n;i++){
            coins-=costs[i];
            if(coins<0) return i;
        }
        return n;
    }
};
