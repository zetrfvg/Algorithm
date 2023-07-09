/*
转换题意：将整个数组中间切k-1刀，分成k段，切一刀的代价是相邻两个元素之和，枚举出所有相邻元素的和，取最大的k-1个和最小的k-1个元素做差即为答案
*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> diff;
        for(int i=1;i<n;i++) diff.push_back(weights[i]+weights[i-1]);
        sort(diff.begin(),diff.end());
        long long ans=0;
        for(int l=0,r=n-2;l<k-1;l++,r--){
            ans+=diff[r]-diff[l];
        }
        return ans;
    }
};
