/*
用set来维护打开的灯泡的位置，对于每个灯泡，二分的找到它的前驱、后继判断它们之间黑灯泡是否为k即可
*/
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> st;
        const int lim=1e6;
        st.insert(-lim);
        st.insert(lim);
        for(int i=0;i<bulbs.size();i++){
            auto b=st.insert(bulbs[i]).first;
            auto a=prev(b),c=next(b);
            if(*a!=-lim&&bulbs[i]-*a-1==k) return i+1;
            if(*c!=lim&&*c-bulbs[i]-1==k) return i+1;
        }
        return -1;
    }
};
