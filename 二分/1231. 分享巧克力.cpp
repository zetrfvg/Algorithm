/*
二分答案，check每次枚举的答案是否满足至少能把巧克力分成k+1块
*/
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n=sweetness.size();
        int l=*min_element(sweetness.begin(),sweetness.end()),r=1e9;
        auto check=[&](int m){
            int res=0,cur=0;
            for(int i=0;i<n;i++){
                cur+=sweetness[i];
                if(cur>=m){
                    res++,cur=0;
                }
            }
            return res>=k+1;
        };
        while(l<r){
            int m=(l+r+1)>>1;
            if(check(m)) l=m;
            else r=m-1;
        }
        return l;
    }
};
