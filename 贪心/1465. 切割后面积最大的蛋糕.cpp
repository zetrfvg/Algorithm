/*
枚举最长的长和宽即可
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int a=0,b=0;
        for(int i=1;i<horizontalCuts.size();i++){
            a=max(a,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            b=max(b,verticalCuts[i]-verticalCuts[i-1]);
        }
        return 1LL*a*b%((int)1e9+7);
    }
};
