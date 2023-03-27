class Solution {
public:
    int kItemsWithMaximumSum(int a, int b, int c, int k) {
        vector<int> g;
        while(a--) g.push_back(1);
        while(b--) g.push_back(0);
        while(c--) g.push_back(-1);
        return accumulate(g.begin(),g.begin()+k,0);
    }
};
