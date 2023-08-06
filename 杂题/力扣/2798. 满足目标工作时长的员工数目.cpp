/*
模拟
*/
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans=0;
        for(auto c:hours) ans+=c>=target;
        return ans;
    }
};
