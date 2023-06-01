/*
维护两个堆，前一半元素用大根堆less维护，后一半元素用小根堆more维护
因为这里使用了延迟删除的技巧，不能用size()获取堆中准确的元素个数，这里额外用size_less,size_more来记录两个堆堆中的元素数量
同时用一个belong数组来记录每个元素当前属于哪个堆中，借此来实现size_less,size_more的维护
如果k为奇数，规定始终让less比great的元素多一个
模拟实现即可，细节较多
*/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> less;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> more;
        int n=nums.size(),size_less=0,size_more=0;
        vector<double> ans;
        vector<int> belong(n);
        for(int i=0;i<n;i++){
            if(!size_less||nums[i]<less.top().first){
                less.push({nums[i],i});
                belong[i]=1;
                size_less++;
            }else{
                more.push({nums[i],i});
                belong[i]=2;
                size_more++;
            }
            while(size_less-size_more>=2){
                more.push(less.top());
                belong[less.top().second]=2;
                less.pop();
                size_less--;
                size_more++;
            }
            while(size_more-size_less>=1){
                less.push(more.top());
                belong[more.top().second]=1;
                more.pop();
                size_more--;
                size_less++;
            }
            while(!less.empty()&&i-less.top().second>=k) less.pop();
            while(!more.empty()&&i-more.top().second>=k) more.pop();
            if(i>=k-1){
                if(k&1) ans.push_back((double)less.top().first);
                else ans.push_back((double)less.top().first/2+(double)more.top().first/2);
                belong[i-k+1]==1?size_less--:size_more--;
            }
        }
        return ans;
    }
};
