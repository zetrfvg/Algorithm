/*
排序后判断情况，case很多需要细想
*/
class Solution {
public:
    int countWays(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans=a[0]>0;
        int n=a.size();
        for(int i=0;i<a.size();i++){
            if(a[i]<i+1){
                if(i!=n-1&&a[i+1]>i+1) ans++;
                else if(i==n-1) ans++;
            }
        }
        return ans;
    }
};
