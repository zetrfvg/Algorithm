/*
对于仓库为位置pos，它能放的箱子的最大值为进仓库到pos这个途中所有位置的最小高度，首先预处理出所有位置pos能放的箱子的最大高度
基于贪心的思想，按高度依次从小到大向仓库放箱子可得最优解
*/
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n=warehouse.size(),m=boxes.size();
        for(int i=1;i<n;i++) warehouse[i]=min(warehouse[i],warehouse[i-1]);
        int ans=0;
        sort(boxes.begin(),boxes.end());
        for(int i=0,j=n-1;i<m&&~j;j--){
            if(warehouse[j]>=boxes[i]) i++,ans++;
        }
        return ans;
    }
};
