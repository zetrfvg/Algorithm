/*
首先将各个坐标与location映射为一个以location为原点的坐标系下
其次将每个点相对于location的位置转化为角度，这里用atan2函数，覆盖区间为[-π,π]，转化为弧度制之后存在数组p种，然后对所有坐标排序
双指针枚举右端点，如果覆盖的区间的角度超过了angle则移动左指针，枚举合法区间的长度的最大值即可
因为存在可能从第四象限覆盖到第一象限的情况，因为角度的旋转呈一个环形
为了把这种情况一般化，我们破环成链，把p整个数组复制一份放到p之后，同时，所有赋值的角度需要加上2π
剩下的就是双指针枚举的经典情况了
*/
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> p;
        int ans=0,same=0;
        for(auto &point:points){
            if(point[0]==location[0]&&point[1]==location[1]){
                same++;
                continue;
            }
            p.push_back(atan2(point[1]-location[1],point[0]-location[0]));
        }
        sort(p.begin(),p.end());
        int m=p.size();
        for(int i=0;i<m;i++){
            p.push_back(p[i]+2*M_PI);
        }
        for(int l=0,r=0;r<m*2;r++){
            while(p[l]+angle*M_PI/180<p[r]){
                l++;
            }
            ans=min(m,max(ans,r-l+1));
        }
        return same+ans;
    }
};
