/*
找到序列中元素个数最多的元素，其个数为c
如果c没有超过数组的一半，则数组可以全部删完(数组长为奇数会剩1)
否则答案为n-(n-c)*2;
*/
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> p;
        int n=nums.size(),mx=0;
        for(auto c:nums) mx=max(mx,++p[c]);
        if(mx*2<=n) return (n&1);
        else return n-(n-mx)*2;
    }
};
