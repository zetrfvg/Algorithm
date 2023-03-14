/*
对于每个点的贡献value[j]-j是固定的
所以枚举元素的同时，维护value[i]+i的最大值即可
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=0,mx=values[0];
        for(int i=1;i<n;i++){
            ans=max(ans,values[i]+mx-i);
            mx=max(mx,values[i]+i);
        }
        return ans;
    }
};
