/*
枚举所有分割位置
*/
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=count(nums.begin(),nums.end(),1);
        vector<int> ans{0};
        int mx=b;
        for(int i=0;i<n;i++){
            nums[i]?b--:a++;
            if(a+b>mx){
                ans.clear();
                ans.push_back(i+1);
                mx=a+b;
            }else if(a+b==mx){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
