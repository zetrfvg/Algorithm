/*
枚举长度增加1，数组num=num*10+1，我们用一个哈希表来维护num对k的余数，出现重复余数时还无法被k整除，说明无解
*/
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int d=1%k,len=1;
        unordered_set<int> st;
        st.insert(1);
        while(1){
            if(!d) return len;
            d=(d*10+1)%k,len++;
            if(st.count(d)) return -1;
            st.insert(d);
        }
        return -1;
    }
};
