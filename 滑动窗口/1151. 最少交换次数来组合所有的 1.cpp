/*
记1个个数为s，滑窗枚举所有长为s的区间
统计各个区间中0的个数，0的个数即为把所有1聚集到该区间的操作次数，答案为最小值
*/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int ans=1e9;
        int s=count(data.begin(),data.end(),1);
        int cnt=0;
        for(int l=0,r=0;r<n;r++){
            cnt+=data[r];
            if(r>=s-1){
                ans=min(ans,s-cnt);
                cnt-=data[l++];
            }
        }
        return ans;
    }
};
