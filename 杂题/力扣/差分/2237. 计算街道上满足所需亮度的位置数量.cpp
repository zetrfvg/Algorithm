/*
题目需要区间修改，用差分数组模拟，最后统一检查requirement即可
*/
class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> diff(n+1);
        for(auto lg:lights){
            diff[max(0,lg[0]-lg[1])]++;
            diff[min(n,lg[0]+lg[1]+1)]--;
        }
        int ans=0,pow=0;
        for(int i=0;i<n;i++){
            pow+=diff[i];
            if(pow>=requirement[i]) ans++;
        }
        return ans;
    }
};
