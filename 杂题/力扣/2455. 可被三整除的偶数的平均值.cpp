class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s=0,cnt=0;
        for(auto c:nums){
            if(c%3==0&&c%2==0){
                s+=c;
                cnt++;
            }
        }
        return cnt?s/cnt:0;
    }
};
