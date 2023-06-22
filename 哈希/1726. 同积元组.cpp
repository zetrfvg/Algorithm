/*
模拟计数
*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> g;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=g[nums[i]*nums[j]]*8;
                g[nums[i]*nums[j]]++;
            }
        }
        return ans;
    }
};
