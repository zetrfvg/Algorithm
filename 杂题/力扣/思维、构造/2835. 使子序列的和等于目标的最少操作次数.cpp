/*
从小到大枚举target的各个二进制位，只有是1的情况下才可能要进行操作
如果能从各个小的数字合并来得到该位置的1，则无需操作把更大的数减半；
否则只能分解大的数，基于贪心，我们从比该位置大的数中选一个最小的来进行分解即可
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        if(accumulate(nums.begin(),nums.end(),0LL)<target) return -1;
        map<int,int> mp;
        set<int> st;
        sort(nums.begin(),nums.end());
        for(auto c:nums) mp[c]++,st.insert(c);
        int ans=0;
        for(int i=0,j=0;i<=30;i++){
            if(target&(1<<i)){
                while(1){
                    auto p=st.lower_bound(1<<i);
                    int w=*p;
                    if(w==(1<<i)){
                        if(!--mp[w]) st.erase(st.find(w));
                        break;
                    }
                    mp[w/2]+=2;
                    st.insert(w/2);
                    ans++;
                    if(!--mp[w]) st.erase(st.find(w));
                }
            }
            mp[1<<(i+1)]+=mp[1<<i]/2;
            if(mp[1<<(i+1)]) st.insert(1<<(i+1));
            
        }
        return ans;
    }
};
