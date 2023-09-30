/*
播种的总时间是固定的，因此考虑排列如何种花
基于贪心，优先种growTim大的花，排序后枚举各个花的结束时间即为答案
*/
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<int> ids(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](const auto &i,const auto &j){
            return growTime[i]>growTime[j];
        });
        int pre=0,ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,pre+plantTime[ids[i]]+growTime[ids[i]]);
            pre+=plantTime[ids[i]];
        }
        return ans;
    }
};
