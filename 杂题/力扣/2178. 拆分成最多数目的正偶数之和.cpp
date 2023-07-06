/*
从小到大枚举偶数即可
*/
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum&1) return ans;
        long long u=2;
        while(finalSum){
            if(finalSum>=u) ans.push_back(u);
            else ans.back()+=finalSum;
            finalSum=max(finalSum-u,0LL);
            u+=2;
        }
        return ans;
    }
};
