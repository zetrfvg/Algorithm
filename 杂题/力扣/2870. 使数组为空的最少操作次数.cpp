/*
哈希表统计元素个数，如果存在个数为1的元素为无解
元素x出现次数为c，清空x的操作数为(c+2)/3   //向上取整
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> p;
        for(auto c:nums) p[c]++;
        int ans=0;
        for(auto &[b,c]:p){
            if(c==1) return -1;
            ans+=(c+2)/3;
        }
        return ans;
    }
};
