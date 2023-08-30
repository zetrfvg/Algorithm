/*
与LIS一样的思想
维护一个非递减的序列
枚举obs[i]，在序列中二分找到第一个严格大于obs[i]的位置p，则满足以obs[i]结尾的最长长度为p+1，然后用obs[i]更新序列上第p个元素即可
*/
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> d,ans;
        for(auto ob:obstacles){
            if(!d.size()||ob>=d.back()){
                d.push_back(ob);
                ans.push_back(d.size());
            }else{
                auto p=upper_bound(d.begin(),d.end(),ob)-d.begin();
                ans.push_back(p+1);
                d[p]=ob;
            }
        }
        return ans;
    }
};
