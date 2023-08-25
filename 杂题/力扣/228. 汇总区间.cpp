/*
按题意模拟即可
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n&&nums[j]==nums[j+1]-1) j++;
            string t=to_string(nums[i]);
            if(i!=j){
                t+="->";
                t+=to_string(nums[j]);
            }
            ans.push_back(t);
            i=j+1;
        }
        return ans;
    }
};
