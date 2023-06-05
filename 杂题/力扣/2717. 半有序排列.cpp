/*
模拟即可
*/
class Solution {
public:
    int semiOrderedPermutation(vector<int>& a) {
        int i=0,j=0;
        int n=a.size();
        while(a[i]!=1) i++;
        while(a[j]!=n) j++;
        int ans=i+n-j-1;
        if(i>j) ans--;
        return ans;
    }
};
