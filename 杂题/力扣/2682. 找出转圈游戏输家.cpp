/*
模拟
*/
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> d(n);
        vector<int> ans;
        int v=1,p=0;
        d[0]=1;
        while(1){
            int t=(p+v++*k)%n;
            if(d[t]==1) break;
            d[t]=1;
            p=t;
        }
        for(int i=0;i<n;i++){
            if(!d[i]){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
