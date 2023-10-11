/*
对于两个数x,y执行操作，如果x,y的二进制数在第p位上不一样，则x获得1<<p，y失去1<<p
基于贪心，我们需要把尽可能多的1都放到更大的数上，原则就是能放就放
对数组降序排序，对于nums[i]，如果它位置p上为1，找到它之前位置p上不为1的最大数，把这个1交换给它
最后答案取前k大个数即可
*/
class Solution {
public:
    int maxSum(vector<int>& a, int k) {
        const int mod=1e9+7;
        int n=a.size();
        sort(a.begin(),a.end(),greater<>());
        vector<queue<int>> p(31);
        for(int i=0;i<n;i++){
            for(int j=0;j<=30;j++){
                if(a[i]&(1<<j)&&!p[j].empty()){
                    a[p[j].front()]|=(1<<j);
                    p[j].pop();
                    a[i]&=~(1<<j);
                }
            }
            for(int j=0;j<=30;j++){
                if(~a[i]&(1<<j)) p[j].push(i);
            }
        }
        int ans=0;
        for(int i=0;i<k;i++) ans=(ans+1LL*a[i]*a[i]%mod)%mod;
        return ans;
    }
};
