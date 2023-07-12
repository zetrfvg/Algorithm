/*
模拟
*/
class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> a;
        while(n){
            a.push_back(n%10);
            n/=10;
        }
        int ans=0;
        int u=1;
        for(int i=a.size()-1;~i;i--){
            ans+=a[i]*u;
            u*=-1;
        }
        return ans;
    }
};
