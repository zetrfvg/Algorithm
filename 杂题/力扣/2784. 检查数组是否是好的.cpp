/*
按题意模拟
*/
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n);
        for(auto c:nums){
            if(c>=n) return false;
            f[c]++;
        }
        for(int i=1;i<n-1;i++){
            if(f[i]!=1) return false;
        }
        return f[n-1]==2;
    }
};
