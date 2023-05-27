/*
两个蚂蚁掉头相当于没掉头，继续前进
*/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;
        for(auto l:left) ans=max(ans,l);
        for(auto r:right) ans=max(ans,n-r);
        return ans;
    }
};
