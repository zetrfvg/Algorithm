/*
每个元素有两个维度[profit,category]
答案要求最大化total_profit+distinct_categories²
首先对所有元素按profit降序排序
基于贪心，选取profit前k个大的元素，此时total_profit达到最大
要想使得答案更大，只能从未选取的元素中选取若干元素来替代已选过的元素，来增大distinct_categories的数量
分类讨论：
1、如果category已在前k大的元素中，且该category的元素仅有一个，则不可被替换
2、如果category已在前k大的元素中，且该category的元素超过一个(设有cnt个)，则有cnt-1个能够被替换
3、如果category不在前k大的元素中，则选category类中profit最大的一个来尝试替换前k大的一个元素(容易知道，未被选的元素中同一种类最多选一个来进行替换)
由此，可以划分出可被替换和可替换的元素
每次替换，从可被替换的元素中选取一个profit最小的，从可替换的元素中选取一个profit最大的进行替换即可，枚举的过程中维护答案的最大值即可
*/
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n=items.size();
        sort(items.begin(),items.end(),greater<>());
        unordered_set<int> st;
        vector<vector<int>> rest,remove;
        long long ans=0,cur=0,cnt=0;
        for(int i=0;i<n;i++){
            if(i<=k-1){
                cur+=items[i][0];
                if(st.count(items[i][1])){
                    remove.push_back(items[i]);
                }else{
                    st.insert(items[i][1]);
                }
                cnt=st.size();
            }else if(!st.count(items[i][1])){
                rest.push_back(items[i]);
                st.insert(items[i][1]);
            }
        }
        ans=cur+cnt*cnt;
        for(int i=0,j=remove.size()-1;i<rest.size()&&j>=0;i++){
            st.insert(rest[i][1]);
            cnt++;
            cur+=rest[i][0]-remove[j--][0];
            ans=max(ans,cur+cnt*cnt);
        }
        return ans;
    }
};
