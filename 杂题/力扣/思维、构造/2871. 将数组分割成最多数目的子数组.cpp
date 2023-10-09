/*
分情况考虑：
元素与和不为0：此时不可分割，任何情况的分割产生的结果一定比不分割的结果更坏
元素与和为0：顺序遍历，依次将遍历的元素求与，一旦与和为0，则做一次分割
*/
class Solution {
public:
    int maxSubarrays(vector<int>& a) {
        int s=~0;
        for(auto c:a) s&=c;
        if(s) return 1;
        int ans=0;
        int n=a.size(),t=~0;
        for(int i=0;i<n;i++){
            t&=a[i];
            if(!t){
                ans++;
                t=~0;
            }
        }
        return ans;
    }
};
