/*
对于每个询问，我们离线按从小到大的顺序回答询问
把元素排序，询问也按大小排序
记suf为后缀和，pre为前缀和
我们双指针来回答所有询问
假设当前回答询问q[j]，我们通过指针移动把所有小于这个询问的值加入前缀和，一共c个，同时后缀和减去这些元素
那么询问q[j]的答案为(c*q[j]-pre)+(suf-(n-c)*q[j])
依次回答所有询问
*/
class Solution {
public:
    vector<long long> minOperations(vector<int>& a, vector<int>& qu) {
        int n=a.size(),m=qu.size();
        vector<vector<long long>> q(m);
        vector<long long> ans(m);
        for(int i=0;i<m;i++){
            q[i]={qu[i],i};
        }
        sort(a.begin(),a.end());
        sort(q.begin(),q.end());
        long long suf=0,pre=0;
        for(auto c:a) suf+=1LL*c;
        int i=0,j=0;
        for(;i<n&&j<m;){
            while(i<n&&a[i]<=q[j][0]){
                pre+=1LL*a[i];
                suf-=1LL*a[i++];
            }
            ans[q[j][1]]=1LL*i*q[j][0]-pre+suf-(n-i)*q[j][0];
            j++;
        }
        while(j<m){
            ans[q[j][1]]=1LL*n*q[j][0]-pre;
            j++;
        }
        return ans;
    }
};
