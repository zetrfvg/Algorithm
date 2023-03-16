/*
因为要求的子数组一定连续
考虑枚举子数组的左端点与右端点
1、首先找到k在数组nums中的位置p
2、枚举左端点i含有多少个大于k的数字，枚举的同时用一个c来维护数的数量
遇到大于k的数就c++，遇到小于k的数就c--
如果c>0则表示从i到p净有c个大于k的数；
如果c<0则表示从i到p净有c个小于k的数
用一个哈希表left来存储含有c的数的左端点有多少个
3、枚举右端点i与枚举左端点同理，用一个哈希表right来记录右端点的数量
4、累计答案
枚举left中的数量为c的左端点个数，则对应right中找到-c和-c+1两个数量的端点个数之和
二者对应保证能够构成一个中位数为k的子数组
二者相乘累积到答案中
依次枚举下去即得答案
5、因为2、3中的枚举分别从nums数组中的位置p-1，p+1开始枚举，
而注意到[k]本身也是满足情况的一个子数组，
所以初始化时要令left[0]=right[0]=1;

时间复杂度：O(n)
*/
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> left,right;
        int p;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                p=i;
                break;
            }
        }
        left[0]=right[0]=1;
        int c=0;
        for(int i=p-1;~i;i--){
            c+=nums[i]>k?1:-1;
            left[c]++;
        }
        c=0;
        for(int i=p+1;i<n;i++){
            c+=nums[i]>k?1:-1;
            right[c]++;
        }
        int ans=0;
        for(auto p:left){
            ans+=p.second*(right[-p.first]+right[-p.first+1]);
        }
        return ans;
    }
};
