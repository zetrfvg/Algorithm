/*
pre记录小于pivot元素的相对位置，suf记录大于pivot元素的相对位置，最后合并即可
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> pre,suf;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot) pre.push_back(nums[i]);
            else if(nums[i]>pivot) suf.push_back(nums[i]);
            else cnt++;
        }
        while(cnt--) pre.push_back(pivot);
        for(auto &c:suf) pre.push_back(c);
        return pre;
    }
};
