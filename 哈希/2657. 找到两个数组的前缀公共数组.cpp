/*
哈希表计数
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> s(n+1),ans(n);
        int c=0;
        for(int i=0;i<n;i++){
            c+=++s[A[i]]==2;
            c+=++s[B[i]]==2;
            ans[i]=c;
        }
        return ans;
    }
};
