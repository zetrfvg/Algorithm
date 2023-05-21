/*
一定是执行完所有的第一种操作，才执行第二种操作
因为vat值域为100，所以我们枚举蓄水次数，累计要执行多少操作取最小值即可
*/
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n=bucket.size();
        int limit=*max_element(vat.begin(),vat.end());
        int ans=1e9;
        for(int i=1;i<=limit;i++){
            int cnt=i;
            for(int j=0;j<n;j++){
                cnt+=max((vat[j]+i-1)/i-bucket[j],0);
            }
            ans=min(ans,cnt);
        }
        return ans==1e9?0:ans;
    }
};
