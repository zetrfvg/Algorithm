/*
滑动窗口，枚举不生气的区间
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int ans=0;
        for(int i=0;i<n;i++) if(!grumpy[i]) ans+=customers[i];
        int cur=ans;
        for(int l=0,r=0;r<n;r++){
            if(grumpy[r]) cur+=customers[r];
            if(r>=minutes){
                if(grumpy[l]) cur-=customers[l];
                l++;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};
