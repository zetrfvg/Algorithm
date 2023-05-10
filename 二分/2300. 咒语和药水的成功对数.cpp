/*
将药水能量排序
二分找到第一个满足大于等的success的位置即可
O(nlogn)
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end(),greater<>());
        int n=spells.size(),m=potions.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(1LL*spells[i]*potions.front()<success){
                ans[i]=0;
                continue;
            }
            int l=0,r=m-1;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(1LL*potions[mid]*spells[i]>=success) l=mid;
                else r=mid-1;
            }
            ans[i]=l+1;
        }
        return ans;
    }
};
