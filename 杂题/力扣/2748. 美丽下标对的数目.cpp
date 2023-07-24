/*
暴力模拟即可
*/
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string c=to_string(nums[i]);
                string d=to_string(nums[j]);
                int x=c[0]-'0',y=d.back()-'0';
                if(__gcd(x,y)==1) ans++;
            }
        }
        return ans;
    }
};
