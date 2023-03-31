/*
由题意不难想到用字典树来维护01串
做两次查询分别查询范围在[0,low]和[0,high]的异或对各有多少个，则满足要求的异或对数量等于这二者的差值

如果做查询query(u,limit)，且当前枚举到第i位
1、如果limit第i位是1，则无论u的第i位是多少，它既可以与0异或也可以与1异或
如果u的第i位异或为0，则无论后面怎样，结果都会小于等limit，直接累加上这个结点的元素数量即可
如果u的第i位异或为1，并且下一个节点存在，则走到下一个结点
2、如果limit的第i是0，则u的第i位经异或之后必须为0才能满足要求
因此只能向下走异或结果为0的结点
*/
class Solution {
public:
    static const int N=20010;
    int tr[15*N][2],idx=0,cnt[15*N];
    void insert(int x){
        int p=0;
        for(int i=15;~i;i--){
            int j=(x>>i)&1;
            if(!tr[p][j]) tr[p][j]=++idx;
            p=tr[p][j];
            cnt[p]++;
        }
    }
    int query(int u,int limit){
        int p=0,res=0;
        for(int i=15;~i;i--){
            int j=(u>>i)&1;
            if((limit>>i)&1){
                if(tr[p][j]) res+=cnt[tr[p][j]];
                if(!tr[p][!j]) return res;
                p=tr[p][!j];
            }else{
                if(!tr[p][j]) return res;
                p=tr[p][j];
            }
        }
        return res+=cnt[p];
    }
    int countPairs(vector<int>& nums, int low, int high) {
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        int ans=0;
        for(auto c:nums){
            ans+=query(c,high)-query(c,low-1);
            insert(c);
        }
        return ans;
    }
};
