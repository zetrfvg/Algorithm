/*
首先筛出1000以内的所有质数
基于贪心的思想，我们希望前面的数减去某个质数后尽可能地小
因此对每个nums中的元素，我们在质数表中二分查找一个满足条件最大的质数
条件是它减去这个质数之后仍然严格大于前一项
*/
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime{0};//0元素防止越界，作为哨兵
        for(int i=2;i<=1000;i++){
            bool ok=1;
            for(int j=2;j*j<=i;j++){
                if(i%j==0) ok=0;
            }
            if(ok) prime.push_back(i);
        }
        int pre=0;
        for(auto &x:nums){
            if(x<=pre) return false;
            auto p=--lower_bound(prime.begin(),prime.end(),x-pre);
            pre=x-*p;
        }
        return true;
    }
};
