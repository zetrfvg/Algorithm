/*
哈希表记录窗口内的元素数即可
*/
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> p;
        int cnt=0;
        for(int l=0,r=0;r<nums.size();r++){
            cnt+=!p[nums[r]]++;
            if(r>=k-1){
                ans.push_back(cnt);
                cnt-=!--p[nums[l++]];
            }
        }
        return ans;
    }
};
