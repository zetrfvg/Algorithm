/*
因为整个数组中支配元素的个数是超过一半的，不难想到，分割之后形成的两个数组的支配元素都是原数组的支配元素
因此枚举下标判断两边的支配元素是否合法即可
*/
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> p;
        int cnt=0,d=0;
        for(auto c:nums){
            if(++p[c]>cnt){
                cnt=p[c];
                d=c;
            }
        }
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=nums[i]==d;
            if(t*2>(i+1)&&(cnt-t)*2>(n-i-1)) return i;
        }
        return -1;
    }
};
