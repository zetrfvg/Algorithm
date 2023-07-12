/*
滑动窗口模拟即可
*/
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int s=0,ans=0;
        for(int i=0;i<calories.size();i++){
            s+=calories[i];
            if(i>=k-1){
                if(s<lower) ans--;
                if(s>upper) ans++;
                s-=calories[i-k+1];
            }
        }
        return ans;
    }
};
