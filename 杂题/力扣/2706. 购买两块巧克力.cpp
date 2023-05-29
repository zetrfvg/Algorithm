/*
排序选最小的两个元素判断即可
*/
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        if(prices[0]+prices[1]>money) return money;
        else return money-prices[0]-prices[1];
    }
};
