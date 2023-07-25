/*
从最后一个元素开始向前合并，如果大于等于前一个元素都能合并
*/
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> b(nums.begin(),nums.end());
        for(int i=b.size()-1;i>0;i--){
            if(b[i-1]<=b[i]) b[i-1]+=b[i];
        }
        return *max_element(b.begin(),b.end());
    }
};
