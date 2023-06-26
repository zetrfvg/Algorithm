/*
枚举购买多少支钢笔
*/
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        for(long long i=0;1LL*i*cost1<=total;i++){
            long long rest=total-1LL*i*cost1;
            ans+=rest/cost2+1;
        }
        return ans;
    }
};
