/*
用一个堆来暴力模拟，对于堆顶元素，是当前所有枚举过的数组中数组和最小的
我们枚举这个数组选取的元素，对于每一个元素，用这个元素所在对应行的下一个元素来代替他，把这个新数组放入堆中。如此，每个数组后继状态对应有m个
枚举到第k个即为答案
以上的做法是基于k很小来实现的
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        set<pair<int,vector<int>>> S;
        int sum=0;
        for(int i=0;i<n;i++) sum+=mat[i][0];
        S.insert({sum,vector<int>(n,0)});
        for(int i=1;i<k;i++){
            auto p=S.begin();
            auto ids=p->second;
            S.erase(p);
            for(int j=0;j<n;j++){
                if(ids[j]+1<m){
                    ids[j]++;
                    int tot=0;
                    for(int u=0;u<n;u++){
                        tot+=mat[u][ids[u]];
                    }
                    S.insert({tot,ids});
                    ids[j]--;
                }
            }
        }
        return S.begin()->first;
    }
};
