/*
暴力模拟
*/
class SparseVector {
public:
    vector<int> v;

    int get(int i){
        return v[i];
    }

    SparseVector(vector<int> &nums) {
        v=nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res=0;
        for(int i=0;i<v.size();i++) res+=v[i]*vec.get(i);
        return res;
    }
};
