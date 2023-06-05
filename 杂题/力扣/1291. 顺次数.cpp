/*
简单枚举即可
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int t=i;
            for(int j=i+1;j<=9;j++){
                t=t*10+j;
                if(t>=low&&t<=high) ans.push_back(t);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
