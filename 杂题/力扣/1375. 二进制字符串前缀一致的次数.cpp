/*
模拟题
*/
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int  n=flips.size();
        vector<int> g(n);
        int pre=0,ans=0;
        for(int i=0;i<n;i++){
            g[flips[i]-1]++;
            pre+=g[i];
            if(flips[i]-1<i) pre++;
            if(pre==i+1) ans++;
        }
        return ans;
    }
};
