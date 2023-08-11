/*
前后缀分解计算每个位置的代价即可
*/
class Solution {
public:
    int bestClosingTime(string customers) {
        int cost=count(customers.begin(),customers.end(),'Y');
        int mn=cost,ans=0;
        customers+='#';
        int n=customers.size();
        for(int i=0;i<=n;i++){
            if(cost<mn) mn=cost,ans=i;
            cost+=customers[i]=='N';
            cost-=customers[i]=='Y';
        }
        return ans;
    }
};
