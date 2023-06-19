/*
哈希表记录元素出现的次数，每次枚举的最小的元素x，如果不存在从x开始的连续k个整数，则返回false
*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> g;
        for(auto c:nums) g[c]++;
        for(auto c:nums){
            if(!g.count(c)) continue;
            for(int i=c,j=0;j<k;i++,j++){
                if(!g.count(i)) return false;
                if(!--g[i]) g.erase(i);
            }
        }
        return true;
    }
};
