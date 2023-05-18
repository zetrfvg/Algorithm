/*
如果第a个和第b个花园都是不完善花园，那么将两个花园之中花数更多那么变为完善花园在整体策略上更优

因此依次枚举将多少花园变为完善花园能够取到最大的美丽值
先将花园按花数排序，我们将花数大于等于target的花园中的数量都置为target，为后续方便操作
用i、j两个指针来模拟，将后(n-i)个花园变完善，将剩下的花全部栽在前j个花园中能够获得的最大值
因为随着完善的花园越来越少，使花园变完善的newFlowers越来越多，那么剩下不完善的花园中的最小值就会越来越大
即随着i增大，j也是增大的，基于这个单调性，可以用双指针来模拟
*/
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n=flowers.size();
        sort(flowers.begin(),flowers.end());
        for(int i=0;i<n;i++){
            flowers[i]=min(flowers[i],target);
        }
        vector<long long> s(n+1);
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+flowers[i];
        }
        long long ans=0;
        for(int i=0,j=0;i<=n;i++){
            long long rest=newFlowers-(1LL*target*(n-i)-(s[n]-s[i]));
            if(rest>=0){
                while(j<i&&rest>=(1LL*flowers[j]*j-s[j])){
                    j++;
                }
                long long pre=0;
                if(j){
                    pre=1LL*partial*min(target-1LL,(rest+s[j])/j);
                }
                ans=max(ans,1LL*full*(n-i)+pre);
                if(i<n&&flowers[i]==target){
                    break;
                }
            }
        }
        return ans;
    }
};
