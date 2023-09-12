/*
工人分裂转化视角来考虑街区合并
每次分裂，选取两个耗时最小的街区x,y来进行合并，得到了一个耗时max(x,y)+split才能建造的新街区，类似哈夫曼树的建立过程，每次贪心的选最小的两个街区合并即可
*/
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int,vector<int>,greater<>> q;
        for(auto b:blocks) q.push(b);
        while(q.size()>1){
            int x=q.top();
            q.pop();
            int y=q.top();
            q.pop();
            q.push(split+y);
        }
        return q.top();
    }
};
