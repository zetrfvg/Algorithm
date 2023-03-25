/*
首先不删除任何元素，找到末尾的最长的非递减子数组的第一个元素位置r
然后枚举要删除区间的左右端点l,r
如果右端点r小于左端点l，则说明r需要右移，一直移动到右端点r大于等于左端点l位置
每次枚举l就找到一个可删除的子数组来更新答案
直到第l个元素小于第l-1个元素为止
*/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        while(r&&arr[r-1]<=arr[r]) r--;
        if(!r) return 0;
        int ans=r;
        for(;!l||arr[l]>=arr[l-1];l++){
            while(r<n&&arr[r]<arr[l]) r++;
            ans=min(ans,r-l-1);
        }
        return ans;
    }
};
