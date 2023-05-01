class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        for(int i=1;i<=bound;i*=x==1?(int)1e9:x){
            for(int j=1;j+i<=bound;j*=y==1?(int)1e9:y){
                ans.push_back(i+j);
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};
