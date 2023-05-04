/*
首先找到左端点的起始位置
然后同向双指针，枚举右端点
移动左端点分两种：
1、双指针枚举的区间中不包含startpos且区间长度大于k时移动左端点
2、双指针枚举的区间中包含startpos且它走的距离超过k时移动左端点
*/
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=lower_bound(fruits.begin(),fruits.end(),startPos-k,[](const auto &a,int b){
            return a[0]<b;
        })-fruits.begin();
        int r=l;
        int s=0,ans=0;
        while(r<fruits.size()&&fruits[r][0]<=startPos+k){
            s+=fruits[r][1];
            while(fruits[r][0]-fruits[l][0]>k){
                s-=fruits[l++][1];
            }
            while(fruits[l][0]<=startPos&&fruits[r][0]>=startPos){
                int left=startPos-fruits[l][0];
                int right=fruits[r][0]-startPos;
                if(min(left,right)*2+max(left,right)<=k) break;
                s-=fruits[l++][1];
            }
            r++;
            ans=max(ans,s);
        }
        return ans;
    }
};
