/*
对于求yi+yj+|xi-xj|的最大值，我们从小到大枚举xi，并在j∈[i-k,i-1]中找到一个值使之最大
因为j必然小于i，所以去绝对值后变为：yi+yj+xi-xj
做移项：xi+yi+yj-xj，因为枚举的i使xi+yi是确定的，我们需要在[i-k,i-1]找到一个j使yj-xj最大，由此考虑单调队列
当xi与队头元素的xj之差超过k时，弹出队头
如果队列不空，此时队头元素是yj-xj最大的，更新答案
然后把队尾元素yj-xj小于xi-yi的弹出队尾，再i入队即可
*/
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans=-1e9;
        int n=points.size();
        deque<int> q;
        for(int i=0;i<n;i++){
            while(!q.empty()&&points[i][0]-points[q.front()][0]>k) q.pop_front();
            if(!q.empty()) ans=max(points[i][0]+points[i][1]+points[q.front()][1]-points[q.front()][0],ans);
            while(!q.empty()&&points[q.back()][1]-points[q.back()][0]<points[i][1]-points[i][0]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
